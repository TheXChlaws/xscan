#include "utils.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

std::string detectPlatform() {
#ifdef _WIN32
    return "Windows";
#else
    std::string termuxCheck = executeCommand("command -v termux-setup-storage");
    if (!termuxCheck.empty() && termuxCheck.find("not found") == std::string::npos) {
        return "Termux";
    }
    
    std::string osRelease = executeCommand("cat /etc/os-release");
    if (osRelease.find("Kali") != std::string::npos) {
        return "Kali Linux";
    }
    
    return "Unknown Unix-like";
#endif
}

std::string executeCommand(const std::string& cmd) {
    char buffer[128];
    std::string result = "";
    
#ifdef _WIN32
    FILE* pipe = _popen(cmd.c_str(), "r");
#else
    FILE* pipe = popen(cmd.c_str(), "r");
#endif
    
    if (!pipe) return "Error executing command";
    
    while (fgets(buffer, sizeof(buffer), pipe != NULL) {
        result += buffer;
    }
    
#ifdef _WIN32
    _pclose(pipe);
#else
    pclose(pipe);
#endif
    
    return result;
}

std::string getCurrentDateTime() {
    auto now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}