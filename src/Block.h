#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {
public:
    int index;
    std::string timestamp;
    std::string data;
    std::string previousHash;
    int nonce;
    std::string hash;

    Block(int idx, const std::string& time, const std::string& dat, const std::string& prevHash);
    std::string calculateHash() const;
};

#endif
