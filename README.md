📘 Mini Search Engine — C++ (C++23)

A lightweight text search engine implemented in modern C++ (C++23).
This project demonstrates how a real search pipeline works:
loading documents, tokenizing text, building an inverted index, and ranking documents based on query relevance.
---------------------------------------------------------------------------------------------------------------
🚀 Features

✔ Recursive document loading (reads all .txt files in nested folders)
✔ Text cleaning & tokenization (lowercasing, removing punctuation, splitting)
✔ Inverted index construction using efficient hash-based structures
✔ Query processing with scoring (simple term-frequency ranking)
✔ Clean modular architecture
✔ Fully written in C++23 using STL
✔ Works cross-platform (Linux, macOS, Windows)
---------------------------------------------------------------------------------------------------------------
🧱 Project Architecture

Mini Search Engine/
│
├── include/
│   ├── DocumentReader.h
│   ├── Tokenizer.h
│   ├── Indexer.h
│   └── SearchEngine.h
│
├── src/
│   ├── DocumentReader.cpp
│   ├── Tokenizer.cpp
│   ├── Indexer.cpp
│   ├── SearchEngine.cpp
│   └── main.cpp
│
├── d1/            ← sample documents for testing
├── CMakeLists.txt
└── README.md
------------------------------------------------------------------------------------------------------------------
🔍 How It Works
1. DocumentReader

Reads all .txt files from a given directory (recursively) and stores:

document ID (filename)

full text content

2. Tokenizer

Normalizes and cleans text:

lowercase

remove punctuation

collapse whitespace

split into tokens

3. Indexer

Builds an inverted index:
token → {doc1, doc2, doc7, ...}

Uses:
std::unordered_map<std::string, std::unordered_set<std::string>>

4. SearchEngine
Processes user query:

tokenizes query

retrieves matching documents

scores them (token frequency)

sorts results by score (descending)

5. main.cpp
Provides a simple interactive CLI:
Enter query: hello world
Results:
 - doc1.txt
 - doc4.txt
------------------------------------------------------------------------------------------------------------------------
🛠 Build Instructions
Prerequisites

CMake 3.16+

C++23 compatible compiler (GCC 13+, Clang 16+, MSVC 2022+)

Build:
mkdir build
cd build
cmake ..
make

Run:
./MiniSearchEngine

📁 Adding Your Own Documents
Put any .txt files inside a folder, for example:
project_root/d1/

The program loads all .txt files recursively.
-----------------------------------------------------------------------------------------------------------------------
🧪 Example

Directory structure:
d1/
  file1.txt   → "hello world"
  file2.txt   → "hello test engine"
  c1/
     file3.txt → "world engine test"

Query:
hello world


Result (scored & sorted):
file1.txt
file2.txt
file3.txt
-----------------------------------------------------------------------------------------------------------------------
🧩 Technologies Used

C++23

STL (std::filesystem, unordered_map, unordered_set, etc.)

CMake for build system

Clean OOP design (DocumentReader, Tokenizer, Indexer, SearchEngine)
-----------------------------------------------------------------------------------------------------------------------
🎯 Educational Goals

This project is ideal for improving:

mastery of C++ strings and STL algorithms

working with std::filesystem

designing class-based architectures

applying hash-based data structures

implementing simple ranking algorithms

building scalable search systems
-----------------------------------------------------------------------------------------------------------------------
👤 Author

Kasra
Master’s student in Computer Science — Berlin
-----------------------------------------------------------------------------------------------------------------------
Q&A
if you have questions, you can contact me with these ways:
Email : kasrabakhshaei25@gmail.com
LinkedIn : www.linkedin.com/in/kasra-bakhshaei-061517336

