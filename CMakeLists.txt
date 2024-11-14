cmake_minimum_required(VERSION 3.10)
project(ShellEmulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(ShellEmulator src/main.cpp src/shell.cpp src/commands.cpp src/filesystem.cpp src/logger.cpp)

# Добавление тестов
enable_testing()
add_executable(test_ls tests/test_ls.cpp)
add_executable(test_cd tests/test_cd.cpp)
add_executable(test_exit tests/test_exit.cpp)
add_executable(test_whoami tests/test_whoami.cpp)
add_executable(test_tac tests/test_tac.cpp)

add_test(NAME test_ls COMMAND test_ls)
add_test(NAME test_cd COMMAND test_cd)
add_test(NAME test_exit COMMAND test_exit)
add_test(NAME test_whoami COMMAND test_whoami)
add_test(NAME test_tac COMMAND test_tac)
