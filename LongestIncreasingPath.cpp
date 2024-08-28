int dfs(vector<vector<int>>&matrix, vector<vector<int>>&memo,int i, int j, int m , int n){
    if(memo[i][j]!=-1)return memo[i][j];
    int maxLen=1;
    //dir array up, down, left , right
    vector<pair<int, int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};

    //explore all 4 dirs
    for(auto& dir:dirs){
        int x=i+dir.first;
        int y=j+dir.second;
        //check if the move within the bounds
        if(x>=0&&y>=0&&x<m&&y<n&&matrix[x][y]>matrix[i][j]){
            //update max len reccurssively
            int length=1+dfs(matrix, memo,x,y,m,n);
            maxLen=max(maxLen, length);
        }

    }memo[i][j]=maxLen;
    return maxLen;
}
        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            if(matrix.empty())return 0;
            int m=matrix.size();
            int n=matrix[0].size();
            int res=0;
            vector<vector<int>>memo(m, vector<int>(n, -1));//memo-> -1
            //apply dfs on each cell
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    res=max(res, dfs(matrix, memo, i, j,m,n));
                }
            }return res;
        }
