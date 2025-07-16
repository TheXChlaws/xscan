#!/bin/bash

echo -e "\033[1;35mInstalling XScan...\033[0m"

# Check for dependencies
if ! command -v cmake &> /dev/null; then
    echo -e "\033[1;33mCMake not found. Installing...\033[0m"
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        sudo apt-get install -y cmake
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        brew install cmake
    else
        echo -e "\033[1;31mUnsupported OS for automatic CMake installation. Please install CMake manually.\033[0m"
        exit 1
    fi
fi

# Create build directory
mkdir -p build
cd build || exit

# Build the project
cmake ..
make

# Install to /usr/local/bin
if [[ "$OSTYPE" == "linux-gnu"* ]] || [[ "$OSTYPE" == "darwin"* ]]; then
    sudo cp xscan /usr/local/bin/
    echo -e "\033[1;32mInstallation complete! You can now run 'xscan' from anywhere.\033[0m"
else
    cp xscan /usr/local/bin/ || cp xscan /usr/bin/
    echo -e "\033[1;32mInstallation complete! You may need to add the installation directory to your PATH.\033[0m"
fi