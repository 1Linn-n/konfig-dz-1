#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <vector>
#include "filesystem.h"
#include "logger.h"

class Shell {
public:
    Shell(int argc, char* argv[]);
    void run();
    std::string getUsername() const;

private:
    std::string username;
    std::string computerName;
    std::string fsPath;
    std::string logPath;
    std::string startupScriptPath;

    void executeCommand(const std::string& command);
    void logAction(const std::string& action);
};

#endif // SHELL_H
