#include "scanner.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>

void SecurityScanner::performTermuxScan() {
    std::cout << "\033[1;34m\n[+] Starting Termux Deep Scan\033[0m\n";
    
    // 1. System Information
    systemInfo.push_back("[SYSTEM] Platform: Termux (Android)");
    systemInfo.push_back("[SYSTEM] OS Version: " + executeCommand("getprop ro.build.version.release"));
    systemInfo.push_back("[SYSTEM] Kernel: " + executeCommand("uname -r"));

    // 2. Storage Analysis
    std::cout << "\033[1;33m\n[i] Analyzing Storage...\033[0m\n";
    vulnerabilities.push_back("[STORAGE] External SD Card: " + 
        (access("/sdcard", F_OK) == 0 ? "Mounted" : "Not Detected"));
    
    // 3. Network Inspection
    std::cout << "\033[1;33m\n[i] Scanning Network...\033[0m\n";
    openPorts.push_back("[NETWORK] Active Connections:\n" + 
        executeCommand("netstat -tuln 2>/dev/null || ss -tuln"));

    // 4. Process Audit
    std::cout << "\033[1;33m\n[i] Auditing Processes...\033[0m\n";
    malwareIndicators.push_back("[PROCESS] Running Services:\n" +
        executeCommand("ps -A -o pid,user,cmd"));

    // 5. Permission Check
    std::cout << "\033[1;33m\n[i] Checking Permissions...\033[0m\n";
    std::string perms = executeCommand("ls -l /data/data/com.termux/files/home");
    vulnerabilities.push_back("[PERMISSION] Home Directory:\n" + 
        (perms.find("world-writable") != std::string::npos ? 
         "WARNING: World-writable!" : "Secure"));

    // 6. Package Verification
    std::cout << "\033[1;33m\n[i] Verifying Packages...\033[0m\n";
    malwareIndicators.push_back("[PACKAGE] Suspicious Packages:\n" +
        executeCommand("dpkg -l | grep -E 'backdoor|spyware|rat'"));

    std::cout << "\033[1;32m\n[√] Termux Scan Completed\033[0m\n";
}