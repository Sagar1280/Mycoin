#include "Block.h"

Block::Block(int idx, const std::string& time, const std::string& dat, const std::string& prevHash)
    : index(idx), timestamp(time), data(dat), previousHash(prevHash), nonce(0), hash("") {}

std::string Block::calculateHash() const {
    // Placeholder hash for now
    return "0000000000000000000000000000000000000000000000000000000000000000";
}
