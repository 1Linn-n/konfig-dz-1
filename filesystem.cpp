#include "filesystem.h"
#include <iostream>
#include <filesystem>

FileSystem::FileSystem(const std::string& path) : rootPath(path), currentPath(path) {}

void FileSystem::listFiles(const std::string& path) {
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::cout << entry.path().filename() << std::endl;
    }
}

void FileSystem::changeDirectory(const std::string& path) {
    currentPath = path;
}

std::string FileSystem::getCurrentPath() const {
    return currentPath;
}
