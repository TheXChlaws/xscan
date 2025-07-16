#!/bin/bash

echo -e "\033[1;35mSetting up XScan for Termux...\033[0m"

# Update packages
pkg update -y

# Install dependencies
pkg install -y cmake clang git

# Clone repository
git clone https://github.com/TheXChlaws/xscan.git
cd xscan || exit

# Build
mkdir -p build
cd build || exit
cmake ..
make

# Install to PATH
cp xscan /data/data/com.termux/files/usr/bin/

echo -e "\033[1;32mXScan setup complete! Run 'xscan' to start scanning.\033[0m"