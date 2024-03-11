#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void Insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }
};

class Solution {
public:
int minExtraChar_helper(TrieNode* root, const string& s, int start, unordered_map<int, int>& momos) {
    if (start == s.length()) {
        return 0;
    }
    if (momos.find(start) != momos.end()) {
        return momos[start];
    }

    int result = INT_MAX;
    TrieNode* currentNode = root;

    for (int i = start; i < s.length(); i++) {
        char ch = s[i];
        if (currentNode->children.find(ch) != currentNode->children.end()) {
            currentNode = currentNode->children[ch];
            if (currentNode->isEndOfWord) {
                result = min(result, minExtraChar_helper(root, s, i + 1, momos));
            }
        } else {
            break;
        }
    }

    int unMatchedChars = s.length() - start - result;
    momos[start] = unMatchedChars;
    return unMatchedChars;
}

int minExtraChar(const string& s, const vector<string>& dictionary) {
    Trie trie;
    for (const string& word : dictionary) {
        trie.Insert(word);
    }
    unordered_map<int, int> momos;  
    return minExtraChar_helper(trie.root, s, 0, momos);
}

};

int main() {
    string s = "leetscode";
vector<string> dictionary = {"leet", "code", "leetcode"};

Solution solution;
int result = solution.minExtraChar(s, dictionary);
cout << result << endl;


    return 0;
}
