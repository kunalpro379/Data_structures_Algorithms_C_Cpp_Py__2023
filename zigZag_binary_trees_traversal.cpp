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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if (root == nullptr) {
            return answer;
        }

        queue<TreeNode*> tree;
        bool zigzag = false;

        tree.push(root);

        while (!tree.empty()) {
            int levelSize = tree.size();
            vector<int> LEVEL(levelSize); // Declare LEVEL here, outside the loop

            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = tree.front();
                tree.pop();

                int index = zigzag ? levelSize - i - 1 : i;

                LEVEL[index] = temp->val; // Assign the value to LEVEL

                if (temp->left) {
                    tree.push(temp->left);
                }
                if (temp->right) {
                    tree.push(temp->right);
                }
            }

            answer.push_back(LEVEL); // Push LEVEL into answer
            zigzag = !zigzag;
        }

        return answer;
    }
};
