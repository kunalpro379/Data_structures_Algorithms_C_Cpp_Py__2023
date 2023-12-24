#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

struct Node
{
char ch;
int Freq;
Node  *left, *right;

};

Node* GetNode(char Ch, int Freq, Node* left, Node* right){


    Node* node=new Node();
    node->ch=Ch;
    node->Freq=Freq;
    node->left=left;
    node-> right=right;
    return node;


}
void Encoding(Node* root, string sequence, unordered_map<char,string>&huffCode){

if(root==NULL){
return;

}
//reached at the leaf
if((root->left==NULL)&&(root->right==NULL)){
huffCode[root->ch]=sequence;

}

Encoding(root->left, sequence+'0', huffCode);
Encoding(root->right, sequence+'1', huffCode);


}


//traversing huff treee
void Decode(Node* root, int &Top, string sequence ){


if(root==NULL){
    return;
}
//leaf
if(root->left==NULL&&root->right){
    cout<<root->ch;
    return;
}
Top++;
if(sequence[Top]='0')
Decode(root->left, Top, sequence);
else
Decode(root->right,Top,sequence);


}

void HuffManTreeBuild(string InputText){
    unordered_map<char, int>freq;
    for(char Char: InputText){freq[Char]++;}// char-frequncyt map 

//leaf node for each char created 

//creating pq for storing leaf nodes of a tree

priority_queue<Node*, vector<Node*>  >PriorQ;
//leaf  nodes creating for each unique character
for (auto pair: freq){PriorQ.push(GetNode(pair.first, pair.second,NULL,NULL));}

while(PriorQ.size()!=1){
//loop till we get single node present in the Q

//removeing 2 nodes having highest prior andlowest freq from Q
Node* left=PriorQ.top(); 
PriorQ.pop();
Node* right=PriorQ.top();
PriorQ.pop();


//new ndode creating with these 2 as children and with 
//sum frequency 
//push into the PQ
int sum=left->Freq+right-> Freq;
PriorQ.push(GetNode(NULL, sum, left,right));


}
//root of huffman tree
Node* root=PriorQ.top();

//traversing the huffman tree and storing 
//huffmain code in map
unordered_map<char, string>huffCode;
Encoding(root, "", huffCode);

cout<<"Huffman Codes are "<<"    "<<endl;

for(auto pair: huffCode){
cout<<pair.first<<"  "<<pair.second<<endl;

}
cout<<"Oriuginal text --> "<<InputText<<endl;


//encoded string 
string str="";
for(char C: InputText){
str+=huffCode[C];

}
cout<<"ENcoded String is : "<<endl<<str;







}


int main(){



}