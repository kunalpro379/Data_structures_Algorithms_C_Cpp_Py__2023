//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
//
//1 parent ko point karnewala pointer available karaya  
///node to parent mapping 
//2 LOT
//3 find target
//4 BFS traversal 
///Two data structures 
//



class Solution {
public:
  //create mapping 
  //return target node
    Node* CreateParentMapping(Node* root, int Target, map<Node*, Node*>& NodeToParent) {
        Node* temp = NULL;
        queue<Node*> Q;
        Q.push(root);
        
        while (!Q.empty()) {
            Node* front = Q.front();
            Q.pop();
            
            if (front->data == Target) {
                temp = front;
            }

            if (front->left) {
                NodeToParent[front->left] = front;
                Q.push(front->left);
            }

            if (front->right) {
                NodeToParent[front->right] = front;
                Q.push(front->right);
            }
        }
        return temp;
    }

    int BurnTree(Node* root, map<Node*, Node*>& NodeToParent) {
        map<Node*, bool> visited;
        queue<Node*> Q;
        Q.push(root);
        visited[root] = true;
        int TimeAns = 0;

        while (!Q.empty()) {
            bool help = false;
            int Size = Q.size();

            for (int i = 0; i < Size; i++) { //preocessiong Neighbouring Nodes
                Node* front = Q.front();
                Q.pop();

                if (front->left && !visited[front->left]) {
                    help = true;
                    Q.push(front->left);
                    visited[front->left] = true;
                }

                if (front->right && !visited[front->right]) {
                    help = true;
                    Q.push(front->right);
                    visited[front->right] = true;
                }

                if (NodeToParent[front] && !visited[NodeToParent[front]]) {
                    help = true;
                    Q.push(NodeToParent[front]);
                    visited[NodeToParent[front]] = true;
                }
            }

            if (help) {
                TimeAns++;
            }
        }
        return TimeAns;
    }

    int minTime(Node* root, int target) {
        map<Node*, Node*> NodeToParent;
        Node* TargetNode = CreateParentMapping(root, target, NodeToParent);
        int TimeAns = BurnTree(TargetNode, NodeToParent);
        return TimeAns;
    }
};
