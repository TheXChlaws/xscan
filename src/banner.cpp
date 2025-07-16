#include "banner.h"
#include <iostream>

void displayBanner() {
    std::cout << getColoredBanner() << std::endl;
}

void displayHelp() {
    std::cout << "\n\033[1;33mXScan - Cross-Platform Security Scanner\033[0m\n";
    std::cout << "\033[1;37mUsage: xscan [options]\033[0m\n\n";
    std::cout << "Options:\n";
    std::cout << "  -h, --help     Show this help message\n";
    std::cout << "  -v, --version  Show version information\n\n";
    std::cout << "\033[1;32mDesigned by X-Chlaws\033[0m\n";
}

std::string getColoredBanner() {
    std::string banner = R"(
    \033[1;35m╔═╗┌─┐┌─┐┌─┐  \033[1;36m╔═╗┌─┐┌─┐┌┬┐┬ ┬┌─┐┬─┐
    \033[1;35m╚═╗├┤ ├─┤│ │  \033[1;36m╚═╗│  ├─┤ │ ├─┤├┤ ├┬┘
    \033[1;35m╚═╝└─┘┴ ┴└─┘  \033[1;36m╚═╝└─┘┴ ┴ ┴ ┴ ┴└─┘┴└─

    \033[1;33m██████╗ ███████╗\033[1;34m ██████╗  █████╗ ███╗   ██╗
    \033[1;33m╚════██╗╚════██║\033[1;34m██╔════╝ ██╔══██╗████╗  ██║
    \033[1;33m █████╔╝    ██╔╝\033[1;34m██║  ███╗███████║██╔██╗ ██║
    \033[1;33m██╔═══╝    ██╔╝ \033[1;34m██║   ██║██╔══██║██║╚██╗██║
    \033[1;33m███████╗   ██║  \033[1;34m╚██████╔╝██║  ██║██║ ╚████║
    \033[1;33m╚══════╝   ╚═╝  \033[1;34m ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝

    \033[1;31mCross-Platform Security Scanner
    \033[1;32mDesigned by X-Chlaws\033[0m
    )";

    return banner;
}
