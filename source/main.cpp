#include <iostream>
#include <vector>
#include "Block.h"

using namespace std;

// Simple function to verify the integrity of the entire blockchain
bool isChainValid(const vector<Block>& chain, int difficulty) {
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& current = chain[i];
        const Block& previous = chain[i - 1];

        // Recalculate the hash and compare
        if (current.hash != current.calculateHash()) {
            cout << "Invalid hash at block " << current.index << "\n";
            return false;
        }

        // Check linkage
        if (current.previousHash != previous.hash) {
            cout << "Broken chain between blocks "
                 << previous.index << " and " << current.index << "\n";
            return false;
        }

        // Optional: ensure Proof-of-Work is satisfied
        string target(difficulty, '0');
        if (current.hash.substr(0, difficulty) != target) {
            cout << "Block " << current.index << " was not mined properly.\n";
            return false;
        }
    }
    return true;
}

int main() {
    vector<Block> blockchain;
    int difficulty = 4;  // Number of leading zeros required

    // --- Create & Mine Genesis Block ---
    cout << "Mining genesis block...\n";
    Block genesisBlock(0, "Genesis Block", "0");
    genesisBlock.mineBlock(difficulty);
    blockchain.push_back(genesisBlock);

    // --- Create & Mine Block #1 ---
    cout << "\nMining block 1...\n";
    Block secondBlock(1, "Transaction 1: Alice pays Bob", blockchain.back().hash);
    secondBlock.mineBlock(difficulty);
    blockchain.push_back(secondBlock);

    // --- Create & Mine Block #2 ---
    cout << "\nMining block 2...\n";
    Block thirdBlock(2, "Transaction 2: Bob pays Charlie", blockchain.back().hash);
    thirdBlock.mineBlock(difficulty);
    blockchain.push_back(thirdBlock);

    // --- Print All Blocks ---
    cout << "\n=== Blockchain ===\n";
    for (const auto& block : blockchain) {
        cout << "Block #" << block.index << "\n";
        cout << "Data: " << block.data << "\n";
        cout << "Previous Hash: " << block.previousHash << "\n";
        cout << "Current Hash: " << block.hash << "\n";
        cout << "Nonce: " << block.nonce << "\n";
        cout << "Timestamp: " << ctime(&block.timestamp);
        cout << "-------------------------\n";
        cout << endl;
    }

    // --- Validate Chain ---
    cout << "\nValidating blockchain... ";
    bool valid = isChainValid(blockchain, difficulty);
    cout << (valid ? "All good! Chain is valid.\n" : "Chain is invalid!\n");

    return 0;
}
