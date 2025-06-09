#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>
#include <sstream>
#include "sha256.h"
#include <iomanip>

using namespace std;

class Block {
public:
    int index;
    string data;
    string previousHash;
    string hash;
    time_t timestamp;

    Block(int idx, const string& data, const string& prevHash)
        : index(idx), data(data), previousHash(prevHash), timestamp(time(nullptr)) {
        hash = calculateHash();
    }

    string calculateHash() const {
        stringstream ss;
        ss << index << timestamp << data << previousHash;
        return sha256(ss.str());
    }
};

#endif
