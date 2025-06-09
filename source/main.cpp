#include <iostream>
#include <vector>
#include "Block.h"

using namespace std;

int main() {
    vector<Block> blockchain;

    // Genesis Block (first block)
    Block genesisBlock(0, "Genesis Block", "0");
    blockchain.push_back(genesisBlock);

    // Add 2 more blocks with dummy transactions
    Block secondBlock(1, "Transaction 1: Alice pays Bob", blockchain.back().hash);
    blockchain.push_back(secondBlock);

    Block thirdBlock(2, "Transaction 2: Bob pays Charlie", blockchain.back().hash);
    blockchain.push_back(thirdBlock);

    // Print all blocks
    for (const auto& block : blockchain) {
        cout << "Block #" << block.index << "\n";
        cout << "Data: " << block.data << "\n";
        cout << "Previous Hash: " << block.previousHash << "\n";
        cout << "Current Hash: " << block.hash << "\n";
        cout << "Timestamp: " << block.timestamp << "\n";
        cout << "-------------------------\n";
        cout << endl;
    }

    return 0;
}
