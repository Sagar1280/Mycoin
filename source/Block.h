#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include "sha256.h"

using namespace std;

class Block {
public:
    int index;
    string sender;
    string receiver;
    double amount;
    string previousHash;
    string hash;
    time_t timestamp;
    string readableTimestamp;
    int nonce;

    Block(int index, const string& sender, const string& receiver, double amount, const string& prevHash)
        : index(index), sender(sender), receiver(receiver), amount(amount), previousHash(prevHash),
          timestamp(time(nullptr)), nonce(0), hash("") {
        readableTimestamp = string(ctime(&timestamp));
        readableTimestamp.pop_back();  // remove newline
    }

    string calculateHash() const {
        stringstream ss;
        ss << index << timestamp << sender << receiver << amount << previousHash << nonce;
        return sha256(ss.str());
    }

    void mineBlock(int difficulty);
};

#endif
