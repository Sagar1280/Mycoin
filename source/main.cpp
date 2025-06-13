#include <iostream>
#include <vector>
#include <map>
#include "Block.h"
#include "Transaction.h"

using namespace std;

bool isChainValid(const vector<Block>& chain, int difficulty) {
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& current = chain[i];
        const Block& previous = chain[i - 1];

        if (current.hash != current.calculateHash()) {
            cout << "Invalid hash at block " << current.index << "\n";
            return false;
        }

        if (current.previousHash != previous.hash) {
            cout << "Broken chain between blocks "
                 << previous.index << " and " << current.index << "\n";
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
    vector<Transaction> transactionPool;
    map<string, double> walletBalances;
    int difficulty = 4;

    cout << "Mining genesis block...\n";
    vector<Transaction> genesisTxs = { Transaction("system", "Alice", 100.0) };
    walletBalances["Alice"] = 100.0;
    Block genesisBlock(0, genesisTxs, "0");
    genesisBlock.mineBlock(difficulty);
    blockchain.push_back(genesisBlock);

    transactionPool.push_back(Transaction("Alice", "Bob", 20.0));
    transactionPool.push_back(Transaction("Bob", "Charlie", 15.0));

    cout << "\nMining block with transactions from pool...\n";
    Block txBlock(1, transactionPool, blockchain.back().hash);
    txBlock.mineBlock(difficulty);
    blockchain.push_back(txBlock);

    for (const auto& tx : transactionPool) {
        if (walletBalances[tx.sender] >= tx.amount) {
            walletBalances[tx.sender] -= tx.amount;
            walletBalances[tx.receiver] += tx.amount;
        } else {
            cout << "❌ Transaction failed (insufficient funds): " << tx.sender << " -> " << tx.receiver << "\n";
        }
    }
    transactionPool.clear();

    cout << "\n=== Blockchain ===\n";
    for (const auto& block : blockchain) {
        cout << "Block #" << block.index << "\n";
        cout << "Timestamp: " << block.readableTimestamp << "\n";
        cout << "Previous Hash: " << block.previousHash << "\n";
        cout << "Hash: " << block.hash << "\n";
        cout << "Nonce: " << block.nonce << "\n";
        cout << "Transactions:\n";
        for (const auto& tx : block.transactions) {
            cout << "  - " << tx.sender << " -> " << tx.receiver << " : " << tx.amount << "\n";
        }
        cout << "-------------------------\n\n";
    }

    cout << "\nValidating blockchain... ";
    bool valid = isChainValid(blockchain, difficulty);
    cout << (valid ? "All good! Chain is valid.\n" : "Chain is invalid!\n");

    return 0;
}