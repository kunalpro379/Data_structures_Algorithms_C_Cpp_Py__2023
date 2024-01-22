#include<iostream>

//analysis
//worst case-> O(h)
//auxillary space-> O(1)

using namespace std;
struct node{
    int key;
    struct node *left,*right;
};
struct node* newNode(int data)
{
    struct node* temp=new struct node;
    temp->key=data;
    temp->left=temp->right=NULL;
    return temp;
}
struct node* insert(struct node* node,int key){

if (node == NULL)
return newNode(key);

if (key<node->key)
{
    node->left=insert(node->left,key);
}
else if(key>node->key)
{
    node->right=insert(node->right,key);

}
return node;
}
struct node* deleteNode(){

}

struct node* search(struct node* root,int key){
if(root==NULL||root->key==key){
    return root;
}
if(root->key<key){
return search(root->right,key);
}
return search(root->left,key);

}
int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    // Key to be found
    int key = 6;
 
    // Searching in a BST
    if (search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;
 
    key = 60;
 
    // Searching in a BST
    if (search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;
    return 0;
}
