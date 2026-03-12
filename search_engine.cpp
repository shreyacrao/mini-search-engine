#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// word -> (document -> frequency)
unordered_map<string, unordered_map<string, int>> invertedIndex;

// convert word to lowercase
string normalize(string word) {
    for (char &c : word) {
        c = tolower(c);
    }
    return word;
}

// add document to index
void indexDocument(string filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Could not open " << filename << endl;
        return;
    }

    string word;
    while (file >> word) {
        word = normalize(word);
        invertedIndex[word][filename]++;
    }

    file.close();
}

// search keyword
void search(string keyword) {
    keyword = normalize(keyword);

    if (invertedIndex.find(keyword) == invertedIndex.end()) {
        cout << "No results found\n";
        return;
    }

    vector<pair<string, int>> results;

    for (auto &doc : invertedIndex[keyword]) {
        results.push_back({doc.first, doc.second});
    }

    // sort by frequency
    sort(results.begin(), results.end(),
         [](pair<string, int> a, pair<string, int> b) {
             return a.second > b.second;
         });

    cout << "Search Results:\n";
    for (auto &r : results) {
        cout << r.first << " (score: " << r.second << ")\n";
    }
}

int main() {

    vector<string> documents = {
        "doc1.txt",
        "doc2.txt",
        "doc3.txt"
    };

    // index documents
    for (string doc : documents) {
        indexDocument(doc);
    }

    cout << "Mini Search Engine Ready!\n";

    while (true) {
        string query;
        cout << "\nEnter keyword (or exit): ";
        cin >> query;

        if (query == "exit")
            break;

        search(query);
    }

    return 0;
}