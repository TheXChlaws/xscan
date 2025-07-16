#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>

class SecurityScanner {
public:
    void performTermuxScan();
    void performKaliScan();
    void performWindowsScan();
    void saveResults(const std::string& filename);
    
    std::vector<std::string> getDetectedVulnerabilities() const;
    std::vector<std::string> getOpenPorts() const;
    std::vector<std::string> getMalwareIndicators() const;
    std::vector<std::string> getSystemInfo() const;

private:
    std::vector<std::string> vulnerabilities;
    std::vector<std::string> openPorts;
    std::vector<std::string> malwareIndicators;
    std::vector<std::string> systemInfo;
    
    void checkCommonVulnerabilities();
    void checkNetworkConfig();
    void checkSuspiciousProcesses();
    void checkWebcamStatus();
    void checkCallForwarding();
};

#endif