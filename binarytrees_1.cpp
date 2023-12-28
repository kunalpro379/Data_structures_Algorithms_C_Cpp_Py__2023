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
}
// In the main function, you need to assign the result of the BuildTree function to the root variable. Currently, you're passing root as a parameter to BuildTree, but it doesn't actually modify the root variable. You should change it like this:
// cpp
// Copy code
// Binode* root = BuildTree(root);
// In the BuildTree function, you should check for the condition data == 0 before creating a new node. Otherwise, you'll create a node with data 0 and continue building the tree. Modify it like this:
// cpp
// Copy code
// root = new Binode(data);
// if (data == 0) {
//     return NULL;
// }
// In the levelsOrderTraversal function, you are missing spaces or newlines between the printed data. You can modify it to make the output more readable:
// cpp
// Copy code
// cout << temp->data << " "; // Add a space after each node's data