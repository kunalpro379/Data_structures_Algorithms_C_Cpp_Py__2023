#include<iostream>

#include<vector>
using namespace std;

class TrieNodes {
public:
    char data;
    TrieNodes* children[26];
    bool isTerminal;

    TrieNodes(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNodes* root;

    Trie() {
        root = new TrieNodes('\0');
    }

    void insertUtil(TrieNodes* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNodes* child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNodes(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }
    public:
void printSuggestions(TrieNodes* current, vector<string >&temp,string prefix){
if(current->isTerminal){
    temp.push_back(prefix);
    return;
}
for(char ch='a';ch<='z';ch++){
    TrieNodes* next=current->children[ch-'a'];
    if(next!=NULL){prefix.push_back(ch);
    printSuggestions(next,temp,prefix);
    prefix.pop_back();}
}



}
    vector<vector<string >>getSuggesstions(string &str){

TrieNodes* prev=root;
vector<vector<string >>output;
string prefix="";
for(int i=0;i<str.length();i++){
int lastCh=str[i];
prefix.push_back(lastCh);  
//cheak for lastCh 
TrieNodes* current=prev->children[lastCh-'a'];
//iff notn found 
if(current ==NULL){
    break;
}

//if foiund
vector<string>temp;
printSuggestions(current ,temp,prefix);
output.push_back(temp);
temp.clear();
prev=current;//updating prev


}
return output;
    }


vector<vector<string>>phoneDirectory(vector<string>&contactList,string &queryStr){

Trie * T=new Trie();
//inserting conctacts in Trie

for (int i=0;i<contactList.size();i++){
string str=contactList[i];
T->insertWord(str);


}
return getSuggesstions(queryStr);
}};
int main(){}