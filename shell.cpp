#include "shell.h"
#include "commands.h"
#include "filesystem.h"
#include "logger.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

Shell::Shell(int argc, char* argv[]) {
    // Инициализация параметров из командной строки
    if (argc < 6) {
        std::cerr << "Usage: ShellEmulator <username> <computerName> <fsPath> <logPath> <startupScriptPath>" << std::endl;
        exit(1);
    }
    username = argv[1];
    computerName = argv[2];
    fsPath = argv[3];
    logPath = argv[4];
    startupScriptPath = argv[5];

    // Инициализация файловой системы и логгера
    fs = new FileSystem(fsPath);
    logger = new Logger(logPath);
}

void Shell::run() {
    // Запуск стартового скрипта
    std::ifstream startupScript(startupScriptPath);
    if (startupScript.is_open()) {
        std::string line;
        while (std::getline(startupScript, line)) {
            executeCommand(line);
        }
        startupScript.close();
    }

    std::string command;
    while (true) {
        std::cout << username << "@" << computerName << "> ";
        std::getline(std::cin, command);
        if (command == "exit") {
            break;
        }
        executeCommand(command);
    }
}

void Shell::executeCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    if (cmd == "ls") {
        std::string path;
        iss >> path;
        if (path.empty()) {
            path = fs->getCurrentPath();
        }
        ls(path);
        logger->logAction("ls " + path);
    } else if (cmd == "cd") {
        std::string path;
        iss >> path;
        if (path.empty()) {
            path = fs->getCurrentPath();
        }
        cd(path);
        logger->logAction("cd " + path);
    } else if (cmd == "whoami") {
        whoami();
        logger->logAction("whoami");
    } else if (cmd == "tac") {
        std::string path;
        iss >> path;
        if (path.empty()) {
            std::cerr << "tac: missing operand" << std::endl;
        } else {
            tac(path);
            logger->logAction("tac " + path);
        }
    } else if (cmd == "exit") {
        logger->logAction("exit");
        exit(0);
    } else {
        std::cerr << "Unknown command: " << cmd << std::endl;
    }
}

void Shell::logAction(const std::string& action) {
    logger->logAction(action);
}

std::string Shell::getUsername() const {
    return username;
}
