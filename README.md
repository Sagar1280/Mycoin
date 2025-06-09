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

## 🔜 To Do
- Replace dummy SHA256 function with a real hash implementation.
- Improve timestamp format (convert to readable string).
- Add file I/O support or JSON export.
