<#
.SYNOPSIS
    XScan Windows Setup Script
.DESCRIPTION
    This script installs dependencies and sets up XScan on Windows systems.
#>

Write-Host "`n`e[1;35mXScan Windows Setup`e[0m`n"

# Check for Chocolatey (package manager)
if (-not (Get-Command choco -ErrorAction SilentlyContinue)) {
    Write-Host "`e[1;33mInstalling Chocolatey...`e[0m"
    Set-ExecutionPolicy Bypass -Scope Process -Force
    [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
    iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
}

# Install dependencies
Write-Host "`e[1;33mInstalling dependencies...`e[0m"
choco install -y cmake --installargs 'ADD_CMAKE_TO_PATH=System'
choco install -y git
choco install -y mingw

# Add MinGW to PATH
$env:Path += ";C:\MinGW\bin"

# Clone repository
Write-Host "`e[1;33mCloning XScan repository...`e[0m"
git clone https://github.com/TheXChlaws/xscan.git
cd xscan

# Build
Write-Host "`e[1;33mBuilding XScan...`e[0m"
mkdir build
cd build
cmake ..
cmake --build .

# Add to PATH
Write-Host "`e[1;33mAdding XScan to PATH...`e[0m"
$targetDir = "$env:USERPROFILE\bin"
if (-not (Test-Path $targetDir)) {
    New-Item -ItemType Directory -Path $targetDir | Out-Null
}
Copy-Item .\xscan.exe $targetDir
[Environment]::SetEnvironmentVariable("PATH", "$env:Path;$targetDir", [EnvironmentVariableTarget]::User)

Write-Host "`n`e[1;32mSetup complete! You can now run 'xscan' from any terminal.`e[0m`n"
