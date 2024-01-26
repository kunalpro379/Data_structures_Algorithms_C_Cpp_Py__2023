#include<iostream>
using namespace std;
// kruskals Minimum Spanning tree ALgorithm
//sort all the edges in non decreasing order of their weight
//take smallest edge cheak if it forms cycle with spanning trees,
//if cuycle not formed include this edge else discard
//repeat step 2 untile there are V-1 edges in the spanning trees
#include<algorithm>
#include<vector>
class DSU{   //----> disjoint set data structure created
// what is dsu??
/*
data structure that stores non overlappig or disjoint subset of elements 
supports operations like____
1.adding new sets to the disjoint set
2.merging disjoint sets to a single disjoint set using union operations
3.finding representive of a disjoint set using find operations
4.cheak if two sets are disjoint or not`
*/
    int * parent;
    int * rank;

    public:
        DSU(int n){
            parent =new int[n];
            rank=new int[n];
            for(int i=0;i<n;i++){
                parent[i]=-1;
                rank[i]=1;
            }
        }

        int find(int i){
            if(parent[i]==-1)
                return i;
`
            return parent[i]=find(parent[i]);
        }

        void unite(int x, int y){
            int s1=find(x);
            int s2=find(y);

            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    parent[s1]=s2;
                }
                else if(rank[s1]>rank[s2]){
                    parent[s2]=s1;
                }
                else{
                    parent[s2]=s1;
                    rank[s2]+=1;
                }
            }
        }
};

class Graph{
vector<vector<int>>edgeList;
int v;
public: Graph(int v){this->v=v;}
void addEDge(int x , int y, int z){
    edgeList.push_back({z,x,y})
}
void KruskalMST(){
    
}
};
int main() 
{ 
    Graph g(4); 
    g.addEdge(0, 1, 10); 
    g.addEdge(1, 3, 15); 
    g.addEdge(2, 3, 4); 
    g.addEdge(2, 0, 6); 
    g.addEdge(0, 3, 5); 
  
    // Function call 
    g.kruskals_mst(); 
  
    return 0; 
}