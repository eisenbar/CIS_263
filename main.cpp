#include <iostream>

#include "coin.h""

int main() {

    Coin c;

    Coin *cptr;

    cptr = c.flipped();

    std::cout << "Hello, World!" << std::endl;

    delete cptr;
    return 0;
}