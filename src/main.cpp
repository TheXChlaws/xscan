#include <iostream>
#include <string>
#include <cstdlib>
#include "banner.h"
#include "scanner.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    // Display banner
    displayBanner();

    // Check for help flag
    if (argc > 1 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
        displayHelp();
        return 0;
    }

    // Initialize scanner
    SecurityScanner scanner;
    
    // Detect platform and perform appropriate scan
    std::string platform = detectPlatform();
    std::cout << "\033[1;36mDetected platform: " << platform << "\033[0m\n\n";

    if (platform == "Termux") {
        scanner.performTermuxScan();
    } else if (platform == "Kali Linux") {
        scanner.performKaliScan();
    } else if (platform == "Windows") {
        scanner.performWindowsScan();
    } else {
        std::cerr << "\033[1;31mUnsupported platform detected!\033[0m\n";
        return 1;
    }

    // Save results
    scanner.saveResults("stored_vulnerabilities.txt");
    
    std::cout << "\n\033[1;32mScan completed! Results saved to stored_vulnerabilities.txt\033[0m\n";
    return 0;
}
