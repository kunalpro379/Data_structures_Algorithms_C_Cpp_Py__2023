/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int sum(TreeNode* root,int currentsum=0 ){
        if(root==NULL){return NULL;}
        currentsum=10*currentsum+root->val;
        if(root->left==NULL&&root->right==NULL){return currentsum;}
        int l=sum(root->left, currentsum);
        int r=sum(root->right,currentsum);
        return l+r;
    
    }
    int sumNumbers(TreeNode* root) {
       return sum(root, 0);
    }
};