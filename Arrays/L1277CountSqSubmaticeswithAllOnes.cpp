class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows =matrix.size();
        int cols=matrix[0].size();

        int count=0;
        vector<vector<int >>dp(rows,vector<int>(cols,0));
    //     for(int i=0;i<rows;i++){
    //         dp[i][0]=matrix[i][0];
    //         count+=dp[i][0];
    //     }
    //     for(int j=0;j<cols ;j++){
    //    dp[0][j]=matrix[0][j];
    //         count+=dp[0][j];
    //     }
     for (int i = 0; i < rows; i++) {for (int j = 0; j < cols; j++) {
                dp[i][j] = matrix[i][j];
                count += dp[i][j]; // Count single-cell squares
            }}

        for(int i=1;i<rows;i++){for(int j=1;j<cols;j++){

            // if(i==0||j==0){
            //     dp[i][j]=matrix[i][j];
            // }
                    if(i>0&&j>0&&matrix[i][j]==1){
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                                  count+=dp[i][j]-1;
                    }

        }}
        return count;
    }
};