//AVL tree is a self-balancing Binary Search Tree 
//(BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes. 

//heiht of the avl tree is always o of logn(n->no of nodes)
//5 rotation cases to balance the tree into avl
//1.left left rotation
//2.left right rotation
//3.right right rotation
//4.right left rotation
//5.double rotation
//AVL tree is a self-balancing Binary Search Tree

//steps
//i) normal bst insertion
//2)current node -> one of the ancestor of newly inserted node-> update height of current node
//3)get the balance factor (left subtree height -right subtreeheight) of current node
//4) if balance fact >1 then curr node is unbalanced   -> left or right case 
//5)compare the newly inserted key with the key in the left subtree root
//6) if balance fact < -1 then curr node is unbalanced   -> left or right case
//7)if balance fact >1 and key < curr->left->key then left left case
//8)compare the newly inserted key with the key in the right sub tree root

#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};
int height(Node* n){
    if (n==NULL)
    return 0;

    return n->height;
}
int max(int a,int b){
    return (a>b)?a:b;
}
Node* newNode(int key){
    Node* node=new Node();
    node->key=key;
    node->left=node->right=NULL;
    node->height=1;
    return node;
}
Node* RightRotate(Node* y){
Node* L=y->left;
Node* LR=L->right;

//performing roatn
L->right=y;
y->left=LR;

y->height=max(height(y->left),height(y->right))+1;
L->height=max(height(L->left),height(L->right))+1;
return L;

}
/*
        y
       / \
      L   C
     / \
    A   LR
      L
     / \
    A   y
       / \
      LR   C

*/
Node* LeftRotate(Node* x){
Node* M=x->right;
Node* MR=M->left;

//performing roatn
M->left=x;
x->right=MR;

x->height=max(height(x->left),height(x->right))+1;
M->height=max(height(M->left),height(M->right))+1;
return M;

}

/*
    x
   / \
  A   M
     / \
    MR  C
      M
     / \
    x   C
   / \
  A   MR


*/
int getBalance(Node* N){
if(N==NULL)
return 0;

return height(N->left)-height(N->right);

}
Node* Insert(Node* node, int key){

//1) Perform the normal BST insertion

if(node==NULL)
return (newNode(key));

if(key<node->key)
node->left=Insert(node->left,key);
else if(key>node->key)
node->right=Insert(node->right,key);
else
return node;
//update height of this ancester node 
node->height=1+max(height(node->left),height(node->right));
int balance=getBalance(node);

//left left case
if(balance>1 && key<node->left->key){
    return RightRotate(node);
}
//Right Right case
if(balance<-1&&key>node->right->key){
    return LeftRotate(node);
}
//Left Right case
if(balance>1&& key>node->left->key){
    node->left=LeftRotate(node->left);
    return RightRotate(node);
}
//Right Left case
if(balance<-1&&key<node->right->key){
    node->right=RightRotate(node->right);
    return LeftRotate(node);
}
return node;

}
void preorder(Node* root){
    if(root!=NULL){
        std::cout<<root->key<<"  ";
        preorder(root->left);
        preorder(root->right);  
    }
}
int main()  
{  
    Node *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = Insert(root, 10);  
    root = Insert(root, 20);  
    root = Insert(root, 30);  
    root = Insert(root, 40);  
    root = Insert(root, 50);  
    root = Insert(root, 25);  
      
   
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preorder(root);  
      
    return 0;  
}  