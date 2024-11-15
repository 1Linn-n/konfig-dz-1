#include "logger.h"
#include <fstream>
#include <ctime>

Logger::Logger(const std::string& path) : logPath(path) {}

void Logger::logAction(const std::string& action) {
    std::ofstream logFile(logPath, std::ios_base::app);
    if (logFile.is_open()) {
        std::time_t now = std::time(nullptr);
        char buf[20];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        logFile << buf << "," << action << std::endl;
        logFile.close();
    }
}
