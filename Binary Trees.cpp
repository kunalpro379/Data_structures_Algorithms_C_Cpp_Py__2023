
#include<iostream>
#include<queue>
using namespace std;

struct Binode {
    int data;
    Binode* left;
    Binode* right;
};

// Creating a binary tree node
Binode* binode(int data) {
    Binode* TreeNode = new Binode;
    TreeNode->data = data;
    TreeNode->left = nullptr;
    TreeNode->right = nullptr;
    return TreeNode;
}

// Building the binary tree recursively
Binode* BuildTree(Binode* root) {
    int data;
    cout << "Enter the data (or 0 to stop): ";
    cin >> data;

    if (data == 0) {
        return nullptr;
    }

    if (root == nullptr) {
        root = binode(data);
    }

    cout << "Enter data to insert to the left of " << data << ": ";
    root->left = BuildTree(root->left);

    cout << "Enter data to insert to the right of " << data << ": ";
    root->right = BuildTree(root->right);

    return root;
}
void levelOrderTraverse(Binode* root) {
    if (root == nullptr) {
        return;
    }

    queue<Binode*> q;
    q.push(root);
    q.push(nullptr); // To mark the end of a level

    while (!q.empty()) {
        Binode* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            cout << endl; // Print a newline to indicate the end of a level

            if (!q.empty()) {
                q.push(nullptr); // Mark the end of the next level
            }
        } else {
            cout << temp->data << " "; // Print the data of the current node

            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void preorderTraverse(Binode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}


void postorderTraverse(Binode* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraverse(root->left);
    postorderTraverse(root->right);
    cout << root->data << " ";
}

// Inorder traversal
void inorderTraverse(Binode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraverse(root->left);
    cout << root->data << " ";
    inorderTraverse(root->right);
}

// Deleting the entire tree
void deleteTree(Binode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int treeHeight(Binode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    // Return the maximum of the left and right subtree heights, plus 1 for the current node
    return max(leftHeight, rightHeight) + 1;
}
Binode* deleteKthNode(Binode* root, int k) {
    if (root == nullptr) {
        return nullptr;
    }

    if (k == 1) {
        deleteTree(root);
        return nullptr;
    }

    root->left = deleteKthNode(root->left, k - 1);
    root->right = deleteKthNode(root->right, k - 1);

    return root;
}
void deleteLevel(Binode* root, int level) {
    if (root == nullptr) {
        return;
    }

    if (level == 1) {
        deleteTree(root->left);
        deleteTree(root->right);
        root->left = nullptr;
        root->right = nullptr;
        return;
    }

    // Recursively delete the specified level in left and right subtrees
    deleteLevel(root->left, level - 1);
    deleteLevel(root->right, level - 1);
}

int main() {
    Binode* root = nullptr;
    int choice;
    bool exitFlag = false;

    while (!exitFlag) {
        cout << "\nMenu:\n";
        cout << "1. Build Tree\n";
        cout << "2. Level-order Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Inorder Traversal\n";
        cout << "6. Height of the Tree\n";
        cout << "7. Delete Kth Node\n";
        cout << "8. Delete a Level\n";
        cout << "9. Delete the Entire Tree\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = BuildTree(root);
                break;
            case 2:
                cout << "Level-order traversal: ";
                levelOrderTraverse(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder traversal: ";
                preorderTraverse(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder traversal: ";
                postorderTraverse(root);
                cout << endl;
                break;
            case 5:
                cout << "Inorder traversal: ";
                inorderTraverse(root);
                cout << endl;
                break;
            case 6:
                cout << "Height of the Tree: " << treeHeight(root) << endl;
                break;
            case 7:
                int k;
                cout << "Enter k: ";
                cin >> k;
                root = deleteKthNode(root, k);
                break;
            case 8:
                int level;
                cout << "Enter level to delete: ";
                cin >> level;
                deleteLevel(root, level);
                break;
            case 9:
                deleteTree(root); // Delete the entire tree to prevent memory leaks
                root = nullptr;
                break;
            case 10:
                exitFlag = true;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

