#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
/*
1. res[][], map<int, vector> verticle_order
   que<pair<node, int>>
hori_dist=0
2. que.push(root, horiz_dist)
3. till que empty:
	curr=front of que pair
	q->pop
	node=curr->que->hori_dist
	verticle_order[hori_dist].push_back(node->val)
	
	if(node->left) que.push(node->left, hori_dist-1)
	if(node->right) que.push(node->left, hori_dist+1)

4. vector<int>sort_the_horiz_dist

5. for ht in sorted_hori_dist:
	result.push_back(verticle_order[ht])

6. return result

*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

vector<vector<int>>verticleOrderTraversal(TreeNode* root){
    vector<vector<int>>res;
    if(!root) return res;
    unordered_map<int, vector<int> >verticle_order;
    //Que for bfs

    queue<pair<TreeNode* , int>>que;
    que.push({root, 0});
    while(!que.empty()){
        auto curr=que.front();
        que.pop();
        TreeNode* node=curr.first;
        int horizontal_dist=curr.second;//horizontal distance is 0 

        verticle_order[horizontal_dist].push_back(node->val);

        //push left and right child of node
        if(node-> left ) que.push({node->left, horizontal_dist-1});
        if(node->right)que.push({node->right, horizontal_dist+1});
    }
    vector<int>hori_dist_sorted;
    for(auto& entry: verticle_order) hori_dist_sorted.push_back(entry.first);
    std::sort(hori_dist_sorted.begin(), hori_dist_sorted.end());
    for(auto & hds: hori_dist_sorted) res.push_back(verticle_order[hds]);
    //appending vector of nudes for each hori dist

    return res;
}

TreeNode* TreeFromArry(vector<int>&arr, int ind){
    TreeNode* root=NULL;
    if(ind< arr.size()){
        if(arr[ind]==-1) return NULL;
    
    root=new TreeNode(arr[ind]);
    root->left=TreeFromArry(arr,2*ind+1);
    root->right=TreeFromArry(arr, 2*ind+2);
    }
    return root;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7}; 
    TreeNode* root = TreeFromArry(arr, 0); 

    vector<vector<int>> result = verticleOrderTraversal(root);

      cout << "Vertical Order:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " "; // Print each node value in the current level
        }
        cout << endl; // Move to next line for the next level
    }
return 0;
}
