#include "Block.h"
#include <string>
#include <iostream>

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    do {
        nonce++;
        hash = calculateHash();
    } while (hash.substr(0, difficulty) != target);
    std::cout << "Block mined: " << hash << "  (nonce=" << nonce << ")\n";
}