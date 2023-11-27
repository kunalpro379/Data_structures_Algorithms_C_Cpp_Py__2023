#include<iostream>
using namespace std;
#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
TreeNode* root =NULL;
TreeNode(int data){
    this ->data=data;
    right= left=NULL;
    root->data=data;
}
   
    // Destructor
    ~TreeNode() {
        
        delete left;
        delete right;
    }

  
};




  void inorder(TreeNode* root, std::vector<int>& datas) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, datas);
        datas.push_back(root->val);
        inorder(root->right, datas);
    }