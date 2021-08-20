#define ZeroBuild_IMPLEMENTATION
#include "../src/ZeroBuild.h"

int main(void)
{
    CHAIN(IN(PATH("examples", "pipe.c")),
          CHAIN_CMD(PATH("tools", "rot13")),
          CHAIN_CMD(PATH("tools", "hex")),
          OUT("output.txt"));
    CMD(PATH("tools", "cat"), "output.txt");
    RM("output.txt");

    return 0;
}
