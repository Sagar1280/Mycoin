#include <iostream>
#include <vector>
#include <unordered_map>
#include "Block.h"

using namespace std;

// Simple function to verify the integrity of the entire blockchain
bool isChainValid(const vector<Block>& chain, int difficulty) {
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& current = chain[i];
        const Block& previous = chain[i - 1];

        if (current.hash != current.calculateHash()) {
            cout << "Invalid hash at block " << current.index << "\n";
            return false;
        }

        if (current.previousHash != previous.hash) {
            cout << "Broken chain between blocks " << previous.index << " and " << current.index << "\n";
            return false;
        }

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
    int difficulty = 4;
    unordered_map<string, double> walletBalances;

    // Initial balances
    walletBalances["Alice"] = 100.0;
    walletBalances["Bob"] = 50.0;
    walletBalances["Charlie"] = 0.0;

    // --- Genesis Block ---
    cout << "Mining genesis block...\n";
    Block genesisBlock(0, "System", "Alice", 0, "0");
    genesisBlock.mineBlock(difficulty);
    blockchain.push_back(genesisBlock);

    // --- Block 1: Alice -> Bob ---
    cout << "\nMining block 1...\n";
    string sender1 = "Alice";
    string receiver1 = "Bob";
    double amount1 = 30.0;

    if (walletBalances[sender1] >= amount1) {
        Block block1(1, sender1, receiver1, amount1, blockchain.back().hash);
        block1.mineBlock(difficulty);
        blockchain.push_back(block1);
        walletBalances[sender1] -= amount1;
        walletBalances[receiver1] += amount1;
    } else {
        cout << "❌ Transaction failed: insufficient balance\n";
    }

    // --- Block 2: Bob -> Charlie ---
    cout << "\nMining block 2...\n";
    string sender2 = "Bob";
    string receiver2 = "Charlie";
    double amount2 = 25.0;

    if (walletBalances[sender2] >= amount2) {
        Block block2(2, sender2, receiver2, amount2, blockchain.back().hash);
        block2.mineBlock(difficulty);
        blockchain.push_back(block2);
        walletBalances[sender2] -= amount2;
        walletBalances[receiver2] += amount2;
    } else {
        cout << "❌ Transaction failed: insufficient balance\n";
    }

    // --- Print Blockchain ---
    cout << "\n=== Blockchain ===\n";
    for (const auto& block : blockchain) {
        cout << "Block #" << block.index << "\n";
        cout << "Sender: " << block.sender << "\n";
        cout << "Receiver: " << block.receiver << "\n";
        cout << "Amount: " << block.amount << "\n";
        cout << "Timestamp: " << block.readableTimestamp << "\n";
        cout << "Previous Hash: " << block.previousHash << "\n";
        cout << "Hash: " << block.hash << "\n";
        cout << "Nonce: " << block.nonce << "\n";
        cout << "-------------------------\n\n";
    }

    // --- Validate Chain ---
    cout << "\nValidating blockchain... ";
    bool valid = isChainValid(blockchain, difficulty);
    cout << (valid ? "All good! Chain is valid.\n" : "Chain is invalid!\n");

    // --- Print Final Balances ---
    cout << "\n=== Final Wallet Balances ===\n";
    for (const auto& [wallet, balance] : walletBalances) {
        cout << wallet << ": " << balance << "\n";
    }

    return 0;
}
