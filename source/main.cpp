#include <iostream>
#include "Block.h"

int main() {
    Block genesisBlock(0, "2025-06-08 10:00:00", "Genesis Block", "0");
    genesisBlock.hash = genesisBlock.calculateHash();

    std::cout << "Genesis Block created with hash: " << genesisBlock.hash << std::endl;
    return 0;
}
