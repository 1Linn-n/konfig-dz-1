#include "shell.h"

int main(int argc, char* argv[]) {
    Shell shell(argc, argv);
    shell.run();
    return 0;
}
