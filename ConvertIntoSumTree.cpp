#include<iostream>
using namespace std;


#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Binode {
public:
    int data;
    Binode* left;
    Binode* right;

    Binode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Binode* BuildTree(Binode* root) {
    int data;
    cout << "enter the data\n";
    cin >> data;
    root = new Binode(data);
    if (data == 0) {
        return NULL;
    } else {
        cout << "enter data to insert to the left\n";
        root->left = BuildTree(root->left);
        cout << "enter data to insert to the right\n";
        root->right = BuildTree(root->right);
        return root;
    }
}

int  ConvertIntoSumTree(Binode* root ){
if(root==NULL){
return 0;
}
else{
    // int leftAns=ConvertIntoSumTree(root->left);
    // int rightAns=ConvertIntoSumTree(root->right);
    root->data=root->data+ConvertIntoSumTree(root->left)+ConvertIntoSumTree(root->right);
    return root->data;
}
}
void levelsOrderTraversal(Binode* root) {
    queue<Binode*> q;
    Binode* temp;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " "; // Add a space after each node's data
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Binode* root = NULL;

    root = BuildTree(root);
    levelsOrderTraversal(root);
    ConvertIntoSumTree(root);
     levelsOrderTraversal(root);
}
