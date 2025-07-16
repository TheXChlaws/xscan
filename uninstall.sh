#!/bin/bash

echo -e "\033[1;35mXScan Uninstaller\033[0m"

# Check if installed
if ! command -v xscan &> /dev/null; then
    echo -e "\033[1;31mXScan is not installed.\033[0m"
    exit 1
fi

# Remove binary
echo -e "\033[1;33mRemoving XScan binary...\033[0m"
sudo rm -f /usr/local/bin/xscan

# Remove build directory if exists
if [ -d "build" ]; then
    echo -e "\033[1;33mRemoving build directory...\033[0m"
    rm -rf build
fi

echo -e "\n\033[1;32mXScan has been successfully uninstalled.\033[0m\n"