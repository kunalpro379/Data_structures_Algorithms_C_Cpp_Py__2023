#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isSafe(vector<vector<int>>&mat, vector<vector<bool>>&visited,int x,int y)
{
    return (x>=0&&x<mat.size()&&y>=0&&y<mat[0].size())&&(mat[x][y]==1&&!visited[x][y]) ;
}

void findShortestPathLength(vector<vector<int>>&Mat, vector<vector<bool>>&visited,int x,int y,int i,int j,int &min_dist,int dist){
if(){

}


}







int main()
{
    vector<vector<int>> mat ={{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
  
    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(3, 4);
    int dist = findShortestPathLength(mat, src, dest);
    if (dist != -1)
        cout << "Shortest Path is " << dist;
     
    else
        cout << "Shortest Path doesn't exist";
   
    return 0;
}