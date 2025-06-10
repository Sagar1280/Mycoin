# 🪙 Mycoin - Simplified Blockchain in C++

This project implements a basic blockchain using C++. Each block stores:
- Index
- Transaction data
- Hash of the previous block
- Current block's hash

The SHA-256 hashing is handled using a custom `sha256.cpp` implementation (currently dummy), avoiding OpenSSL for simplicity and portability.

---

## 🧠 Project Structure


---

## 🚧 Development Log

### 📅 2025-06-09
- 🔧 Setup C++ blockchain project structure with `main.cpp`, `Block.h`, and dummy `sha256` implementation.
- 💥 Resolved linker issues from OpenSSL by replacing with `sha256.cpp`.
- 🧱 Created and printed a small chain of blocks with:
  - Data
  - Previous hash
  - Current hash
- ⏱️ Timestamp included for each block using `time(nullptr)`, but not yet human-readable.
- ✅ Verified block creation and hash chaining.
- 📂 Set up `main` branch as default on GitHub.
- 📌 Commit history cleaned and organized.

---
## 📅 2025-06-10
- 🔐 Replaced dummy SHA-256 implementation with a real SHA-256 algorithm in sha256.cpp, including <cstdint> for fixed-width       integer types.
- ⚙️ Implemented proof-of-work mechanism with difficulty and nonce in Block::mineBlock to ensure hashes meet the required leading zeros.
- 🛠️ Fixed mineBlock redefinition error by removing redundant implementation from Block.cpp and keeping it inline in Block.h (or moved to Block.cpp with declaration in Block.h).
- 📤 Pushed updated files (main.cpp, Block.h, Block.cpp, sha256.h, sha256.cpp) to the main branch of the Mycoin GitHub repository under the source directory.
- ✅ Verified blockchain functionality with block mining and chain validation.

## 🔜 To Do
- Improve timestamp format (convert to readable string).
- Add file I/O support or JSON export.
