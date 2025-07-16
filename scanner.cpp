#include "scanner.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

void SecurityScanner::performTermuxScan() {
    std::cout << "\033[1;34mStarting Termux security scan...\033[0m\n";
    
    // Get system information
    systemInfo.push_back("Platform: Termux");
    systemInfo.push_back("Android Version: " + executeCommand("getprop ro.build.version.release"));
    
    // Perform checks
    checkCommonVulnerabilities();
    checkNetworkConfig();
    checkSuspiciousProcesses();
    checkWebcamStatus();
    checkCallForwarding();
}

void SecurityScanner::performKaliScan() {
    std::cout << "\033[1;34mStarting Kali Linux security scan...\033[0m\n";
    
    // Get system information
    systemInfo.push_back("Platform: Kali Linux");
    systemInfo.push_back("Kernel Version: " + executeCommand("uname -r"));
    
    // Perform checks
    checkCommonVulnerabilities();
    checkNetworkConfig();
    checkSuspiciousProcesses();
    checkWebcamStatus();
}

void SecurityScanner::performWindowsScan() {
    std::cout << "\033[1;34mStarting Windows security scan...\033[0m\n";
    
    // Get system information
    systemInfo.push_back("Platform: Windows");
    systemInfo.push_back("OS Version: " + executeCommand("ver"));
    
    // Perform checks
    checkCommonVulnerabilities();
    checkNetworkConfig();
    checkSuspiciousProcesses();
    checkWebcamStatus();
}

void SecurityScanner::checkCommonVulnerabilities() {
    std::cout << "\033[1;33mChecking for common vulnerabilities...\033[0m\n";
    // Add actual vulnerability checks here
    vulnerabilities.push_back("Checking for outdated packages...");
    vulnerabilities.push_back("Checking for weak permissions...");
}

void SecurityScanner::checkNetworkConfig() {
    std::cout << "\033[1;33mChecking network configuration...\033[0m\n";
    // Add network checks here
    openPorts.push_back("Checking open ports...");
}

void SecurityScanner::checkSuspiciousProcesses() {
    std::cout << "\033[1;33mChecking for suspicious processes...\033[0m\n";
    // Add process checks here
    malwareIndicators.push_back("Scanning for malware indicators...");
}

void SecurityScanner::checkWebcamStatus() {
    std::cout << "\033[1;33mChecking webcam status...\033[0m\n";
    // Add webcam checks here
    vulnerabilities.push_back("Webcam status: Not directly accessible without permissions");
}

void SecurityScanner::checkCallForwarding() {
    std::cout << "\033[1;33mChecking call forwarding status...\033[0m\n";
    // Add call forwarding checks here
    vulnerabilities.push_back("Call forwarding: Requires telephony permissions to check");
}

void SecurityScanner::saveResults(const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "=== XScan Security Report ===\n\n";
        
        outFile << "=== System Information ===\n";
        for (const auto& info : systemInfo) {
            outFile << info << "\n";
        }
        
        outFile << "\n=== Detected Vulnerabilities ===\n";
        for (const auto& vuln : vulnerabilities) {
            outFile << vuln << "\n";
        }
        
        outFile << "\n=== Open Ports ===\n";
        for (const auto& port : openPorts) {
            outFile << port << "\n";
        }
        
        outFile << "\n=== Malware Indicators ===\n";
        for (const auto& malware : malwareIndicators) {
            outFile << malware << "\n";
        }
        
        outFile << "\nScan completed at: " << getCurrentDateTime() << "\n";
        outFile.close();
    } else {
        std::cerr << "\033[1;31mError: Could not save results to file!\033[0m\n";
    }
}

std::vector<std::string> SecurityScanner::getDetectedVulnerabilities() const {
    return vulnerabilities;
}

std::vector<std::string> SecurityScanner::getOpenPorts() const {
    return openPorts;
}

std::vector<std::string> SecurityScanner::getMalwareIndicators() const {
    return malwareIndicators;
}

std::vector<std::string> SecurityScanner::getSystemInfo() const {
    return systemInfo;
}