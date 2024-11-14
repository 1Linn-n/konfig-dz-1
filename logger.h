#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    Logger(const std::string& path);
    void logAction(const std::string& action);

private:
    std::string logPath;
};

#endif // LOGGER_H
