
//recurssion-->
#include<limits.h>

/*
int slv(int n,int x,int y, int z){

		if(n==0)
	return 0;
if(n<0)
return INT_MIN;

int a=slv(n-x,x,y,z)+1;
int b=slv(n-y,x,y,z);
int c=slv(n-z,x,y,z);
int ans=max(a,max(b,c));
return ans;
}


int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int ans=slv(n,x,y,z);
	if(ans<0)
	return 0;

	else return ans;


}


//using dynamic pro----->

int slvMem(int n,int x,int y, int z,vector<int>&dp){

		if(n==0)
	return 0;
if(n<0)
return INT_MIN;

if(dp[n]!=-1){
    return dp[n];
}

int a=slvMem(n-x,x,y,z,dp)+1;
int b=slvMem(n-y,x,y,z,dp)+1;
int c=slvMem(n-z,x,y,z,dp)+1;
dp[n]=max(a,max(b,c));
return dp[n];
}


int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
vector<int>dp(n+1,-1);
int ans=slvMem(n,x,y,z,dp);
	if(ans<0)
	return 0;

	else return ans;


}


*/

//using tabulation

int slvTAB(int n, int x, int y, int z) {
vector<int>dp(n+1,INT_MIN);
dp[0]=0;
for (int i=1;i<=n;i++) {
if(i-x>=0 && dp[i-x]!=-1)
dp[i]=max(dp[i],dp[i-x]+1);

if(i-y>=0 && dp[i-y]!=-1)
dp[i]=max(dp[i],dp[i-y]+1);

if(i-z>=0 && dp[i-z]!=-1)
dp[i]=max(dp[i],dp[i-z]+1);

}
if(dp[n]<0)
return 0;

else 
return dp[n];


}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	return slvTAB(n,x,y,z);

}



