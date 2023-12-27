#include<iostream>
using namespace std;
/*Input: arr[] = {40, 20, 30, 10, 30}
Output: 26000
Explanation:There are 4 matrices of dimensions 40×20, 20×30, 30×10, 10×30.
Let the input 4 matrices be A, B, C and D.
The minimum number of  multiplications are obtained by 
putting parenthesis in following way (A(BC))D.
The minimum is 20*30*10 + 40*20*10 + 40*10*30
*/

#include<vector>
#include <algorithm>

int min(int a, int b) {
    return (a < b) ? a : b;
}
int matrixChainMulMemo(int *ptr  , int left, int right, vector<vector<int>>&dp){
    if(left==right)
    return 0;

    if(dp[left][right]!=-1)
    return dp[left][right];

    dp[right][right]= INT_MAX;

    for(int k=left;k<right;k++){
        dp[left][right]=min(dp[left][right],matrixChainMulMemo(ptr,left,right,dp)+matrixChainMulMemo(ptr,k+1,right,dp)+ptr[left-1]*ptr[k]*ptr[left]);
    }
    return dp[left][right];






}
int main() {
    int p[] = {10, 30, 5, 60};

    int n = sizeof(p) ;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int result = matrixChainMulMemo(p, 0, n - 1, dp);

    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}