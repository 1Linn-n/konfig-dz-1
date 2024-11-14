#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

void ls(const std::string& path);
void cd(const std::string& path);
void whoami();
void tac(const std::string& path);

#endif // COMMANDS_H
