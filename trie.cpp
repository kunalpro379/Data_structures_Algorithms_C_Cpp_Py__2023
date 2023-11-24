#include<iostream>
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

        int index = word[0] - 'A';
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

    bool searchUtil(TrieNodes* root, string word) {
        // base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNodes* child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // Optional: Print all words in the Trie
    void printAllWords(TrieNodes* root, string current) {
        if (root->isTerminal) {
            cout << current << endl;
        }

        for (int i = 0; i < 26; i++) {
            if (root->children[i] != nullptr) {
                printAllWords(root->children[i], current + char('A' + i));
            }
        }
    }

    void printAllWords() {
        printAllWords(root, "");
    }

    // Destructor to free allocated memory
    ~Trie() {
        deleteTrie(root);
    }

private:
    void deleteTrie(TrieNodes* node) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < 26; i++) {
            deleteTrie(node->children[i]);
        }

        delete node;
    }
    bool isEmpty(TrieNodes* root){
for(int i=0;i<30;i++){
    if(root->children[i]!=NULL){
        return false;
    }
    return true;
}

    }
    //removing of word 
    TrieNodes*  RemoveWOrdUtil(TrieNodes* root, string word,int i) {

        if(root==NULL){
            return NULL;
        }
        if(i==word.length()){
            root->isTerminal=false;
            if(isEmpty(root)==true){
            
                root=NULL;
                    delete root;
            }
            return root;
        }
        int index=word[i]-'A';
        root->children[index]=RemoveWOrdUtil(root->children[index],word,i++);
        if(isEmpty(root)&&root->isTerminal==false){}
return root;
        
    }
    public:
   TrieNodes* RemoveWord(string word){
RemoveWOrdUtil(root,word, 0);

    }
};



int main() {
    Trie* T = new Trie();
    cout<<"inserting elemenmts into tires......."<<endl;
    // T->insertWord("AGDFSERQRWRWRDXCZVZBSJN");
    // T->insertWord("RTWYEQSDFACXGHA./tCSVBSJAVFCSDHJAKNMVBCKOBJNIOUHJ");
    // T->insertWord("KJNSFJGKBHRUHG GHJF GDFFHG DSGFKJDGOIYTOUIYT Y LUOYKLJHLKPIKIK");
//     T->insertWord("CMNBMC DCS");
//    T->insertWord("KUNAL JSDHS");
     T->insertWord("KUNAL");
//    T->insertWord("DEEPAK");
   //T->insertWord("CMNBcxmvnxkvjzbnvhkjbfjzvhbhjbhjdbvzjhxbv jhxv zhjbxv xzvxzvxcvMC");

// //T-> searchWord("ndszcJKDCNJ");

T->RemoveWord("KUNAL");
   cout << "Search for 'KUNAL': " << (T->searchWord("KUNALl") ? "Found" : "Not Found") << endl;
    // cout << "Search for 'FNXV': " << (T->searchWord("FNXV") ? "Found" : "Not Found") << endl;
    // cout << "Search for 'FXV': " << (T->searchWord("FXV") ? "Found" : "Not Found") << endl;
 //T->printAllWords();
//T->RemoveWord("KUNAL");
T->searchWord("KUNAL");
    // // cout << "All words in the Trie:" << endl;
   // T->printAllWords();

    
    delete T;

    return 0;
}
