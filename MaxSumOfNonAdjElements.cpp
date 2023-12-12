#include <bits/stdc++.h>
#include <vector>

///recursive soln
/*
int solve(vector<int> &nums, int n) {
  if (n < 0)
    return 0;
  if (n == 0)
    return nums[0];

  int incl = solve(nums,n-2)+nums[n];
  int excl=solve(nums,n-1)+0;

return max(incl,excl);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
int n=nums.size();
int ans=solve(nums,n-1);
return ans;
}

*/


/*
//adding memorzation

#include <bits/stdc++.h>
#include <vector>
int SlvMem(vector<int> &nums, int n,vector<int>&dp ) {
  if (n < 0)
    return 0;
  if (n == 0)
    return nums[0];

    if(dp[n]!=-1)
    return dp[n];

  int incl = SlvMem(nums,n-2,dp)+nums[n];
  int excl=SlvMem(nums,n-1,dp)+0;

dp[n]= max(incl,excl);
return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
int n=nums.size();
vector<int>dp(n,-1);
return SlvMem(nums,n-1,dp);


}

*/


/// using tabulation


#include <bits/stdc++.h>
#include <vector>
int SolveTaboo(vector<int> &nums) {
//   if (n < 0)
//     return 0;
//   if (n == 0)
//     return nums[0];

//     if(dp[n]!=-1)
//     return dp[n];

//   int incl = SlvMem(nums,n-2,dp)+nums[n];
//   int excl=SlvMem(nums,n-1,dp)+0;

// dp[n]= max(incl,excl);
// return dp[n];

//

    int n = nums.size();
    vector<int> dp(n, 0);

    if (n == 0) {
        return 0;
    }

    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
        int incl =  dp[i - 2] + nums[i];
        int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

return SolveTaboo(nums);
 

}


/*


//Space optimization

#include <bits/stdc++.h>
#include <vector>
int Solvespaceoptimizn(vector<int> &nums) {

    int n = nums.size();
    vector<int> dp(n, 0);

   int prev2=0;
   int prev=nums[0];



    for (int i = 1; i < n; i++) {
        int incl = prev2 + nums[i] ;
        int excl = prev;
        dp[i] = max(incl, excl);
        int ans=max(incl, excl);
        prev2=prev;
        prev=ans;
    }

    return prev;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

return Solvespaceoptimizn(nums);
 

}
*/