#!/bin/bash

echo -e "\033[1;35mXScan Kali Linux Setup\033[0m"

# Update package list
echo -e "\033[1;33mUpdating packages...\033[0m"
sudo apt update -y

# Install dependencies
echo -e "\033[1;33mInstalling dependencies...\033[0m"
sudo apt install -y cmake g++ git build-essential libssl-dev net-tools

# Clone repository
echo -e "\033[1;33mCloning XScan repository...\033[0m"
git clone https://github.com/TheXChlaws/xscan.git
cd xscan || exit

# Build
echo -e "\033[1;33mBuilding XScan...\033[0m"
mkdir -p build
cd build || exit
cmake ..
make

# Install system-wide
echo -e "\033[1;33mInstalling XScan...\033[0m"
sudo cp xscan /usr/local/bin/

echo -e "\n\033[1;32mSetup complete! You can now run 'xscan' from anywhere.\033[0m\n"