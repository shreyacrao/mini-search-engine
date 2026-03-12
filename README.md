Mini Search Engine in C++

Overview

This project is a simple Mini Search Engine built using C++. It indexes multiple text documents and allows users to search for keywords through a command-line interface. The search engine uses an inverted index to efficiently map words to the documents in which they appear.
When a user enters a keyword, the program retrieves all documents containing that word and ranks them based on the frequency of the word in each document.

Features

- Builds an inverted index for fast keyword lookup
- Case-insensitive search (treats "Data" and "data" as the same)
- Ranks results based on word frequency
- Supports multiple text documents
- Interactive command-line search interface

How It Works

- The program loads a set of text documents.
- Each word in the documents is converted to lowercase using a normalization function.
- The words are stored in an inverted index data structure.

Structure of the index:

word → document → frequency

Example:

data → {doc1.txt: 2, doc2.txt: 1}
search → {doc3.txt: 3}

When the user enters a keyword:

- The word is normalized.
- The program checks the inverted index.
- All matching documents are retrieved.
- Results are sorted by frequency score.

Project Structure
mini-search-engine
│
├── search_engine.cpp
├── doc1.txt
├── doc2.txt
├── doc3.txt
└── README.md

search_engine.cpp – main program containing indexing and search logic

doc1.txt, doc2.txt, doc3.txt – sample documents used for indexing

README.md – project documentation