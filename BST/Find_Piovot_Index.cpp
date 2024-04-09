struct TreeNode {
        int val;
        char operation;
        TreeNode* root;
        TreeNode* left;
        TreeNode* right;
      TreeNode(char op){
          this->op=operation;
          this->left=this->right=NULL;
          this->op=operation;
      }
    };
class Solution {
    public:
 TreeNode* insert(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }

int FindPivot
    int pivotIndex(vector<int>& nums) {


    }
};