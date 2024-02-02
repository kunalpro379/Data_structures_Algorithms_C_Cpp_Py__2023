#include<iostream>
using namespace std;
#include <string.h>
#include<vector>
//approach1 --> KMP algorithm( done already in another file)
//approach2 --> Dynamic programming
//approach3 --> space optimized approach
//approach4 --> using recurssion

//#2//
int lcs(string &str1, string &str2){
   
int n=str1.size();
int m=str2.size();
int ans=0;
vector<vector<int>>dp(n+1,vector<int>(m+1,0));
for(int j=0;j<=m;j++){dp[0][1]=0;}
for(int i=0;i<=n;i++){dp[1][0]=0;}
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(str1[i-1]==str2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
            ans=max(ans,dp[i][j]);
        }
        else dp[i][j]=0;
return ans;

}
//#3//

//#4//

int main()
{
    //approach1
  string str1 = "GeeksforGeeks";
    string str2 = "GeeksQuiz";
    cout << "Length of Longest Common Substring is " << lcs(str1, str2) << endl;
    return 0;
// //approach2
//     string X = "dddabcaafdgssfdgsdg";
//     string Y = "bbbabcdeffffffff";
//     int m = X.length();
//     int n = Y.length();
 
//     cout << LCSubStr(X, Y, m, n);
// //approach3
//         int n, m;
 
//     X = "abcdxyz";
//     Y = "xyzabcd";
 
//     n = X.size();
//     m = Y.size();
 
//     cout << lcs(n, m, 0);
    return 0;
}