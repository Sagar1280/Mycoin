#include "Block.h"

void Block::mineBlock(int difficulty) {
    string target(difficulty, '0');
    do {
        nonce++;
        hash = calculateHash();
    } while (hash.substr(0, difficulty) != target);

    cout << "Block mined: " << hash << " (nonce=" << nonce << ")\n";
}
