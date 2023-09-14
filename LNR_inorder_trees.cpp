#include<iostream>
#include<vector>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    void LNR(vector<int>&result,TreeNode* root){
         
        if(root==NULL){
            return ;
        }
        else{
       LNR(result,root->left); 
        result.push_back(root->val);
        LNR(result,root->right);
        } 
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
       LNR(result,root);
        return result;
    }
};
int main() {
   // TreeNode* root;

    Solution solution; // Create an instance of the Solution class
    TreeNode* root = new TreeNode(1); // Create a sample binary tree
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result;
    solution.inorderTraversal(root);

    // Now, 'result' contains the in-order traversal of the binary tree
    for (int val : result) {
        cout << val << " ";
    }

    // Don't forget to free the memory allocated for the tree nodes
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
