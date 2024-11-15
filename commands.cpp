#include "commands.h"
#include "shell.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <algorithm>

void ls(const std::string& path) {
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::cout << entry.path().filename() << std::endl;
    }
}

void cd(const std::string& path) {
    std::filesystem::current_path(path);
}

void whoami() {
    Shell shell(0, nullptr);
    std::cout << shell.getUsername() << std::endl;
}

void tac(const std::string& path) {
    std::ifstream file(path);
    if (file.is_open()) {
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
        std::reverse(lines.begin(), lines.end());
        for (const auto& l : lines) {
            std::cout << l << std::endl;
        }
    } else {
        std::cerr << "File not found: " << path << std::endl;
    }
}
