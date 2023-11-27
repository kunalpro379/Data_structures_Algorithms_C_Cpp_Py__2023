#include <iostream>

#include<string>
using namespace std;
#include<vector>
#include<hash_map>
#include<map>
#include<queue>
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

  //create mapping 
  //return target node

// Driver Code
int main() {
    Solution solution;
    string treeString = "1 2 3 N N 4 N N 5 N N";
 TreeNode* root = buildTree(treeString);

    int target = 3;
    int result = solution.minTime(root, target);

    cout << "Minimum time to burn the tree: " << result << endl;

    return 0;
}
