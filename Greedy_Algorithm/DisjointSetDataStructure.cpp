#include<iostream>
using namespace std;
#include<algorithm>

class DSU{   //----> disjoint set data structure created
// what is dsu??
/*
data structure that stores non overlappig or disjoint subset of elements 
supports operations like____
1.adding new sets to the disjoint set
2.merging disjoint sets to a single disjoint set using union operations
3.finding representive of a disjoint set using find operations
4.cheak if two sets are disjoint or not
*/  public:
    int* parent;
    int* rank;

    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

        int find(int i){
            if(parent[i]==-1)
                return i;

            return find(parent[i]);
        }

        void unite(int x, int y){
            int s1=find(x);
            int s2=find(y);

            parent[s1]=s2;
        }//time comp--O(n)

        //optimaztions 
        //union by Rank/Size and path Compression

        //path compression()
        //speeds up data structure by compressing height of the trees
    int Find(int i) {
        if (parent[i] == i)
            return i;
        else {
            int result = find(parent[i]);
            parent[i] = result;
            return result;
        }
    }
        //TC-> O(Logn)
        //Union by Rank
        /*
        rank[] -> new Arr , i is representetive of set , rank[i]-> height of treee representing set
        if we r unitiing two trees or sets  call them left and right and depending on rank of them

        if rank of left is less than rank of right ->move left under right 
        IF RANK  OF right is less thank rank of left -> move right under left
        if ranks are equal->any move doesnt mattr but result rank will be greater than any of the tree

        */
       void UnionByRank(int i, int j) {
        int s1 = find(i);
        int s2 = find(j);
        if (s1 == s2) {
            return;  // Elements are in the same set.
        }
        // Get rank of the first and second tree.
        int Irank = rank[s1];
        int Jrank = rank[s2];
        if (Irank < Jrank) {
            // Rank of the first tree is less than the rank of the second tree.
            this->parent[s2] = s1;  // Move s1 under s2.
        }
        else if (Jrank < Irank) {
            this->parent[s1] = s2;  // Move s2 under s1.
        }
        else {
            // Ranks are equal, move s1 under s2 and increment the rank of s2.
            parent[s1] = s2;
            rank[s2]++;
        }
    }
};
int main() {
    // Create a DSU object with 5 elements (0 to 4).
    DSU dsuObj(5);

    // Perform some union operations.
    dsuObj.UnionByRank(0, 1);
    dsuObj.UnionByRank(2, 3);
    dsuObj.UnionByRank(1, 2);

    // Check if elements 0 and 3 are in the same set.
    if (dsuObj.find(0) == dsuObj.find(3)) {
        cout << "Elements 0 and 3 are in the same set." << endl;
    } else {
        cout << "Elements 0 and 3 are in different sets." << endl;
    }

    // Check if elements 2 and 4 are in the same set.
    if (dsuObj.find(2) == dsuObj.find(4)) {
        cout << "Elements 2 and 4 are in the same set." << endl;
    } else {
        cout << "Elements 2 and 4 are in different sets." << endl;
    }

    return 0;
}
