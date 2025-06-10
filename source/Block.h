#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>
#include <sstream>
#include "sha256.h"
#include <iomanip>
#include <iostream>

using namespace std;

class Block {
public:
    int index;
    string data;
    string previousHash;
    string hash;
    time_t timestamp;
    int nonce;

    // Constructor: sets everything except hash/nonce
    Block(int index, const string& data, const string& prevHash)
        : index(index), data(data), previousHash(prevHash),
          timestamp(time(nullptr)), nonce(0), hash("") {}

    // Calculate SHA256 over all fields including nonce
    string calculateHash() const {
        stringstream ss;
        ss << index << timestamp << data << previousHash << nonce;
        return sha256(ss.str());
    }

    // Declare mineBlock (no implementation here)
    void mineBlock(int difficulty);
};

#endif