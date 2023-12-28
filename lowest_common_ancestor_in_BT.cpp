
  
 struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL ;
        }
        if(root->val==p->val){
            return p;
        }
        if(root->val==q->val){
            return q;
        }
       TreeNode* right= lowestCommonAncestor(root->right,p,q);
           TreeNode* left= lowestCommonAncestor(root->left,p,q);
        
             if(left==NULL&& right!=NULL){return right;}
        else if (right==NULL &&left!=NULL){return left;}
        
        else if (left==NULL&& right==NULL) {return NULL;}
       
        else {return root;}
    }
};