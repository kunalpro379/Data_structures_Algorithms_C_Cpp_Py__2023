#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;  // Declare dp as a global variable


int fib(int n) {
    // base case
    if (n <= 1) {
        return n;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}
int fib2(int n2) {
    // base case
  vector<int>dp(n2+1,-1);


    dp[n2] = dp(n2 - 1) + dp(n2 - 2);
    return dp[n2];
}

int main() {
    int n = 12;

 
    dp.assign(n + 1, -1);

    int result = fib(n);

    cout <<result;



//space optimization technique  
int n3;
cin>>n;
int prev1=1;
int prev2=0;
for(int i=2;i<=n;i++){

int curr=prev1+prev2;
prev2=prev1;
prev1=curr;
cout<<curr<<endl;


}
    return 0;
}

