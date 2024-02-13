#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1); // Initialize size vector with 1
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    
    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        } else {
            return parent[node] = findUltimateParent(parent[node]);
        }
    }
    
    void UnionByRank(int u, int v){
        int ultimateParentOfU = findUltimateParent(u);
        int ultimateParentOfV = findUltimateParent(v);
        
        if(ultimateParentOfU == ultimateParentOfV) return;
        
        if(rank[ultimateParentOfU] < rank[ultimateParentOfV]){
            parent[ultimateParentOfU] = ultimateParentOfV;
        } else if(rank[ultimateParentOfV] < rank[ultimateParentOfU]){
            parent[ultimateParentOfV] = ultimateParentOfU;
        } else {
            parent[ultimateParentOfV] = ultimateParentOfU;
            rank[ultimateParentOfU]++;
        }
    }

    void UnionBySize(int u, int v){
        int ultimateParentOfU = findUltimateParent(u);
        int ultimateParentOfV = findUltimateParent(v);
        if(ultimateParentOfU == ultimateParentOfV) return;

        if(size[ultimateParentOfU] < size[ultimateParentOfV]){
            parent[ultimateParentOfU] = ultimateParentOfV;
            size[ultimateParentOfV] += size[ultimateParentOfU];
        } else {
            parent[ultimateParentOfV] = ultimateParentOfU;
            size[ultimateParentOfU] += size[ultimateParentOfV];
        }
    }
};

int main(){
    DisjointSet ds(7); // Initialize DisjointSet with 7 elements
    ds.UnionByRank(1, 2);
        ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(5, 6);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(3, 7);

    // Check if 3 and 7 belong to the same component
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    // ds.UnionBySize(1, 2);
    // ds.UnionBySize(2, 3);
    // ds.UnionBySize(4, 5);
    // ds.UnionBySize(5, 6);
    // ds.UnionBySize(6, 7);
    return 0;
}


