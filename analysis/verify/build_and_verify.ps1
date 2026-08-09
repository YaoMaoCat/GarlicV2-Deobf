# build_and_verify.ps1
#
# Build the proxy DLL from native/ and compare its SHA-256 against the
# decrypted binary shipped in artifacts/GarlicProxy.dll.
#
# This is the single most decisive test for the "套壳 vs 原创" question:
# if the freshly built DLL matches the shipped DLL byte-for-byte, the
# native/ source tree is provably the source of the proxy.

[CmdletBinding()]
param(
    [string]$Vcvars = "C:\Program Files\Microsoft Visual Studio\18\Insiders\VC\Auxiliary\Build\vcvars64.bat",
    [string]$Generator = "Visual Studio 17 2022",
    [string]$ArtifactDir = "..\..\artifacts",
    [string]$BuildDir   = "build",
    [string]$ExpectedHashFile = "expected.sha256"
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

# Sanity checks
if (-not (Test-Path $Vcvars)) {
    throw "vcvars64.bat not found at: $Vcvars"
}
if (-not (Test-Path (Join-Path $ArtifactDir "GarlicProxy.dll"))) {
    throw "Expected artifact not found: $ArtifactDir\GarlicProxy.dll"
}

function Run-InVcvars {
    param([string]$Cmd)
    $tmp = [System.IO.Path]::GetTempFileName()
    "@`"&$ $Vcvars`" >NUL && $Cmd && exit /B %ERRORLEVEL%" |
        Out-File -FilePath $tmp -Encoding ASCII -Force
    $p = Start-Process -FilePath "cmd.exe" `
        -ArgumentList "/c", $tmp `
        -NoNewWindow -Wait -PassThru
    Remove-Item $tmp -Force -ErrorAction SilentlyContinue
    return $p.ExitCode
}

Write-Host "==> Configuring MSVC" -ForegroundColor Cyan
$vcvarsOut = cmd /c "`"$Vcvars`" && set" 2>&1
if ($LASTEXITCODE -ne 0) { throw "vcvars64.bat failed" }

Write-Host "==> CMake configure ($Generator)" -ForegroundColor Cyan
$repoRoot = (Resolve-Path "$PSScriptRoot\..\..").Path
$cmakeCfg = Run-InVcvars "cmake -S `"$repoRoot`" -B `"$BuildDir`" -G `"$Generator`" -A x64"
if ($cmakeCfg -ne 0) { throw "cmake configure failed ($cmakeCfg)" }

Write-Host "==> Build MinecraftProxy_msvc (Release)" -ForegroundColor Cyan
$cmakeBuild = Run-InVcvars "cmake --build `"$BuildDir`" --target MinecraftProxy_msvc --config Release"
if ($cmakeBuild -ne 0) { throw "cmake build failed ($cmakeBuild)" }

# Locate the built DLL
$candidates = @(
    (Join-Path $BuildDir "Release\MinecraftProxy_msvc.dll"),
    (Join-Path $BuildDir "MinecraftProxy_msvc.dll")
)
$builtPath = $null
foreach ($c in $candidates) {
    if (Test-Path $c) { $builtPath = (Resolve-Path $c).Path; break }
}
if (-not $builtPath) {
    throw "Built DLL not found. Looked in: $($candidates -join ', ')"
}

$artifactPath = (Resolve-Path (Join-Path $ArtifactDir "GarlicProxy.dll")).Path
$builtHash    = (Get-FileHash $builtPath -Algorithm SHA256).Hash.ToLowerInvariant()
$artifactHash = (Get-FileHash $artifactPath -Algorithm SHA256).Hash.ToLowerInvariant()
$expectedHash = $null
if (Test-Path $ExpectedHashFile) {
    $expectedHash = (Get-Content $ExpectedHashFile -Raw).Trim().ToLowerInvariant()
}

Write-Host ""
Write-Host "==> Hashes" -ForegroundColor Cyan
Write-Host ("    built   : " + $builtPath)
Write-Host ("    " + $builtHash)
Write-Host ("    shipped : " + $artifactPath)
Write-Host ("    " + $artifactHash)
if ($expectedHash) {
    Write-Host ("    expected: " + $expectedHash)
}
Write-Host ""

if ($builtHash -eq $artifactHash) {
    Write-Host "==> MATCH: built DLL is byte-identical to shipped DLL." -ForegroundColor Green
    Write-Host "    This proves that native/ is exactly the source of" -ForegroundColor Green
    Write-Host "    artifacts/GarlicProxy.dll." -ForegroundColor Green
    exit 0
} else {
    Write-Host "==> MISMATCH." -ForegroundColor Yellow
    Write-Host "    Possible causes:" -ForegroundColor Yellow
    Write-Host "      - different MSVC version (check with `cl` after vcvars)"
    Write-Host "      - non-deterministic STL hashes"
    Write-Host "      - AV / EDR modifying the output DLL on disk"
    Write-Host "      - native/ source has been modified after the artifact was produced"
    Write-Host ""
    Write-Host "    Try a clean VM with MSVC 19.51 (see expected compiler banner in proxy.md)."
    exit 2
}