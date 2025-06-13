#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include <vector>
#include "sha256.h"
#include "Transaction.h"

using namespace std;

class Block {
public:
    int index;
    vector<Transaction> transactions;
    string previousHash;
    string hash;
    time_t timestamp;
    string readableTimestamp;
    int nonce;

    Block(int idx, const vector<Transaction>& txs, const string& prevHash)
        : index(idx), transactions(txs), previousHash(prevHash),
          timestamp(time(nullptr)), nonce(0), hash("") {
        readableTimestamp = string(ctime(&timestamp));
        readableTimestamp.pop_back();
    }

    string calculateHash() const {
        stringstream ss;
        ss << index << timestamp << previousHash << nonce;
        for (const auto& tx : transactions) {
            ss << tx.sender << tx.receiver << tx.amount;
        }
        return sha256(ss.str());
    }

    void mineBlock(int difficulty);
};

#endif