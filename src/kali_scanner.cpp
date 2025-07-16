#include "scanner.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>

void SecurityScanner::performKaliScan() {
    std::cout << "\033[1;34m\n[+] Starting Kali Linux Forensic Scan\033[0m\n";

    // 1. System Fingerprinting
    systemInfo.push_back("[SYSTEM] Platform: Kali Linux");
    systemInfo.push_back("[SYSTEM] Kernel: " + executeCommand("uname -a"));
    systemInfo.push_back("[SYSTEM] Users: \n" + 
        executeCommand("getent passwd | cut -d: -f1"));

    // 2. Network Recon
    std::cout << "\033[1;33m\n[i] Conducting Network Recon...\033[0m\n";
    openPorts.push_back("[NETWORK] Listening Ports:\n" + 
        executeCommand("ss -tulnp | grep -v '127.0.0.1'"));
    vulnerabilities.push_back("[NETWORK] ARP Table:\n" + 
        executeCommand("arp -a"));

    // 3. Rootkit Detection
    std::cout << "\033[1;33m\n[i] Hunting Rootkits...\033[0m\n";
    malwareIndicators.push_back("[ROOTKIT] Check:\n" + 
        executeCommand("(lsmod | grep -E 'diamon|enyelkm') || echo 'Clean'"));

    // 4. File Integrity
    std::cout << "\033[1;33m\n[i] Validating System Files...\033[0m\n";
    vulnerabilities.push_back("[INTEGRITY] Critical Binaries:\n" + 
        executeCommand("md5sum /bin/bash /usr/bin/sudo 2>/dev/null"));

    // 5. Cron Audit
    std::cout << "\033[1;33m\n[i] Auditing Cron Jobs...\033[0m\n";
    malwareIndicators.push_back("[CRON] Scheduled Tasks:\n" + 
        executeCommand("ls -la /etc/cron* /var/spool/cron"));

    // 6. Privilege Escalation
    std::cout << "\033[1;33m\n[i] Checking PrivEsc Vectors...\033[0m\n";
    vulnerabilities.push_back("[PRIVESC] SUID Files:\n" + 
        executeCommand("find / -perm -4000 -type f 2>/dev/null | head -n 20"));

    std::cout << "\033[1;32m\n[√] Kali Forensic Scan Completed\033[0m\n";
}
