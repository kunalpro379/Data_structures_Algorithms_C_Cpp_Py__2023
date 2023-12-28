//approach 1
/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=3;
        for(int i=0;i<strs[0].length();i++){
            char ch= strs[0][i];
            bool matching =true;
//
for (int j=1;j<n;j++){

//not matchingn 
if(strs[j].size()<i || ch!=strs[j][i]){
    matching=false;
break;
}

}
if(matching==false){break;}
else
ans.push_back(ch);}
return ans;
    }
};

*/


//??

//Approach 2

//using tries 

/*
class Solution {
public:
class TrieNode{
public:
char data;
int childcount;
TrieNode* children[26];
bool isTerminal;


    //coinstructor
TrieNode(char ch){
data =ch;
for (int i=0;i<26;i++){
children[i]=NULL;

}
int childcount=0;
isTerminal=false;

}

};

class Trie{
public:
 TrieNode* root;

 Trie(char ch){root=new TrieNode(ch);
 }
 void InsertWordUtil(TrieNode* root,string word){
     //base case 
if(word.length()==0){
root->isTerminal=true;
return;

}
int index=word[index]-'a';
TrieNode* child;
//present
if(root-> children[index]!=NULL){
child=root->children[index];

}
else{
//absent
child=new TrieNode(word[0]);
root->children[index]=child;
root->childcount++;

}
//recursion
InsertWordUtil(child,word.substr(1));

 }
 void InsertWord(string word){
     InsertWordUtil(root,word);
 }
//  void SearchUtil(){}
//  void SearchWord(){}



//using trie
void lcp(string str, string  &ans){

    for(int i=0;i<str.length();i++){
        char ch =str[i];
        if(root->childcount==1){

            ans.push_back(ch);
            //aage badhte hai
            int index=ch-'a';
            root=root->children[index];
        }
        else{
            break;
        }
        if(root->isTerminal)
        break;
    }
}
    string longestCommonPrefix(vector<string>& strs) {
       //root ko pucha tere kitne child hai 
       //ek child hai toh ture ans me store karliya
       // ek se jyada child hai toh false 

Trie * T =new Trie('\0');
//Strings ko insert karddiya 
for(int i=0; i<strs.size();i++){
T->InsertWord(strs[i]);

}
string first=strs[0];
string ans="";
T->lcp(first, ans);
return ans;
    }
};
};

*/