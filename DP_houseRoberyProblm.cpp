#include <bits/stdc++.h> 

long long int solveTaboo(vector<int>& nums){
 int n=nums.size();
long long int prev2=0;
long long int prev1=nums[0];
for(int i=1;i<n;i++){
    long long int incl=prev2+nums[i];
    long long int excl=prev1+0;
    long long int ans=max(incl,excl);
    prev2=prev1;
    prev1=ans;
}
return prev1;

}


long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.

int n=valueInHouse.size();
if(n==1)
return valueInHouse[0];

vector<int>first,second;
for(int i=0;i<n;i++){
if(i!=n-1)
first.push_back(valueInHouse[i]);

if(i!=0)
second.push_back(valueInHouse[i]);

}
return max(solveTaboo(first), solveTaboo(second));
}