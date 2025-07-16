src/#include "scanner.h"
#include "utils.h"
#include <iostream>
#include <windows.h>
#include <iphlpapi.h>
#include <psapi.h>
#include <tlhelp32.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "psapi.lib")

void SecurityScanner::performWindowsScan() {
    std::cout << "\033[1;34mStarting Windows security scan...\033[0m\n";
    
    // Get basic system information
    systemInfo.push_back("Platform: Windows");
    
    OSVERSIONINFOEX osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    GetVersionEx((OSVERSIONINFO*)&osvi);
    
    std::string osVersion = "Windows Version: " + std::to_string(osvi.dwMajorVersion) + "." + 
                          std::to_string(osvi.dwMinorVersion) + " Build " + 
                          std::to_string(osvi.dwBuildNumber);
    systemInfo.push_back(osVersion);
    
    // Check network configuration
    checkWindowsNetworkConfig();
    
    // Check processes
    checkWindowsProcesses();
    
    // Check webcam status
    checkWindowsWebcamStatus();
    
    // Common vulnerability checks
    checkCommonVulnerabilities();
}

void SecurityScanner::checkWindowsNetworkConfig() {
    std::cout << "\033[1;33mChecking Windows network configuration...\033[0m\n";
    
    // Get active TCP connections
    PMIB_TCPTABLE2 pTcpTable;
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;
    
    pTcpTable = (MIB_TCPTABLE2*)malloc(sizeof(MIB_TCPTABLE2));
    if (pTcpTable == NULL) {
        vulnerabilities.push_back("Failed to allocate memory for TCP table");
        return;
    }
    
    dwSize = sizeof(MIB_TCPTABLE2);
    if ((dwRetVal = GetTcpTable2(pTcpTable, &dwSize, TRUE)) == ERROR_INSUFFICIENT_BUFFER) {
        free(pTcpTable);
        pTcpTable = (MIB_TCPTABLE2*)malloc(dwSize);
        if (pTcpTable == NULL) {
            vulnerabilities.push_back("Failed to allocate memory for TCP table");
            return;
        }
    }
    
    if ((dwRetVal = GetTcpTable2(pTcpTable, &dwSize, TRUE)) == NO_ERROR) {
        for (DWORD i = 0; i < pTcpTable->dwNumEntries; i++) {
            std::string portInfo = "TCP Port: " + std::to_string(ntohs((u_short)pTcpTable->table[i].dwLocalPort)) + 
                                 " State: " + std::to_string(pTcpTable->table[i].dwState);
            openPorts.push_back(portInfo);
        }
    } else {
        vulnerabilities.push_back("Failed to get TCP table");
    }
    
    free(pTcpTable);
}

void SecurityScanner::checkWindowsProcesses() {
    std::cout << "\033[1;33mChecking Windows processes...\033[0m\n";
    
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;
    
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        vulnerabilities.push_back("Failed to create process snapshot");
        return;
    }
    
    pe32.dwSize = sizeof(PROCESSENTRY32);
    
    if (!Process32First(hProcessSnap, &pe32)) {
        vulnerabilities.push_back("Failed to get first process");
        CloseHandle(hProcessSnap);
        return;
    }
    
    do {
        // Check for suspicious processes
        std::string processName = pe32.szExeFile;
        if (processName.find("mimikatz") != std::string::npos || 
            processName.find("powersploit") != std::string::npos) {
            malwareIndicators.push_back("Suspicious process detected: " + processName);
        }
    } while (Process32Next(hProcessSnap, &pe32));
    
    CloseHandle(hProcessSnap);
}

void SecurityScanner::checkWindowsWebcamStatus() {
    std::cout << "\033[1;33mChecking Windows webcam status...\033[0m\n";
    
    // This is a basic check - more advanced would require checking device manager
    vulnerabilities.push_back("Webcam status: Requires manual verification through Device Manager");
}
