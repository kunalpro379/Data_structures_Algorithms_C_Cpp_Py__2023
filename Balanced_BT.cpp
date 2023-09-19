
#include<iostream>
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
    int height(TreeNode* root){
if(root==NULL){

    return 0;
}
int LeftHeight=height(root->left);
int RightHeight=height(root->right);
int ans =1+max(LeftHeight,RightHeight);
return ans;
}
    
    bool isBalanced(TreeNode* root) {
         if(root==NULL){
        return true;
    }
int LeftHeight=height(root->left);
int RightHeight=height(root->right);
int diff=abs(LeftHeight-RightHeight);
bool ans1= (diff<=1);
bool LeftAns=isBalanced(root->left);
bool RightAns=isBalanced(root->right);
if(ans1&&LeftAns&&RightAns){
return  true; 
}
        else{return false;}
        
    }
};
int main(){
    return 0;
}