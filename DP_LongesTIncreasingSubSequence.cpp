/*
Input: arr[] = {3, 10, 2, 1, 20}
Output: 3
Explanation: The longest increasing 
subsequence is 3, 10, 20

Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: 4
Explanation: The longest increasing 
subsequence is {3, 7, 40, 80}
*/
#include<iostream>
#include<vector>
using namespace std;



//  Recurssive && memorization approach
#include <iostream>
#include <vector>

class Solution {
public:
    int longestIncreasingSubsequence(std::vector<int>& cont, int n, std::vector<int>& lusan) {
        if (n == 1) {
            return 1;
        }

        if (lusan[n] != -1) {
            return lusan[n];
        }

        int currentmax = 1;

        for (int i = 0; i < n; i++) {
            int subproblem = longestIncreasingSubsequence(cont, i, lusan);
            if (cont[i] < cont[n - 1] && subproblem + 1 > currentmax) {
                currentmax = subproblem + 1;
            }
        }

        lusan[n] = currentmax;
        return currentmax;
    }

    int lengthOfLISRec(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        std::vector<int> lis_length(n + 1, -1);

        return longestIncreasingSubsequence(nums, n, lis_length);
    }
};


// using memorization

int FunctionMemo(int index, int previous_index, int n, int arr[], vector<vector<int>>&DP){
    if(index==n){
        return 0;
    }

if(DP[index][previous_index]!=-1)
return DP[index][previous_index];

int NotTake=0+FunctionMemo(index+1, previous_index,n,arr,DP);

int Take=-2;
if(previous_index==-1||arr[index]>arr[previous_index])
Take=1+FunctionMemo(index+1,index,n,arr,DP);

return DP[index][previous_index+1]=max(Take,NotTake);

}

 int longestSubsequenceMem(int n, int arr[])
{
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
    return FunctionMemo(0, -1, n, arr, dp);
}


int main() {
    Solution solution;
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n=nums.size();
    int result1 = solution.lengthOfLISRec(nums);

    std::cout << "Output: " << result1 << std::endl;
Solution solution2;
int arr[]={10, 9, 2, 5, 3, 7, 101, 18};
    int result2 = longestSubsequenceMem(n,arr);

    cout << "Length of LIS is: " << result2 << endl;

 
    return 0;
}
