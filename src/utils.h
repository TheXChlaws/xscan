#ifndef UTILS_H
#define UTILS_H

#include <string>

std::string detectPlatform();
std::string executeCommand(const std::string& cmd);
std::string getCurrentDateTime();

#endif
