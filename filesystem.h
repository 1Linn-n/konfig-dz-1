#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>

class FileSystem {
public:
    FileSystem(const std::string& path);
    void listFiles(const std::string& path);
    void changeDirectory(const std::string& path);
    std::string getCurrentPath() const;

private:
    std::string rootPath;
    std::string currentPath;
};

#endif // FILESYSTEM_H
