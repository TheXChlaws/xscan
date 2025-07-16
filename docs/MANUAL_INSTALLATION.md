# Manual Installation Guide

## Prerequisites
- CMake (version 3.10 or higher)
- C++ compiler (GCC, Clang, or MSVC)
- Git (for cloning the repository)

## Installation Steps

### Linux/Unix (including Termux and Kali Linux)
```bash
# Clone the repository
git clone https://github.com/TheXChlaws/xscan.git
cd xscan

# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
make

# Install (optional)
sudo cp xscan /usr/local/bin/
