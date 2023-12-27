//Compute_nCr%p.cpp

//find nCr

/*
#include<iostream>
using namespace std;

int nCr(int n, int k) {
    if (k > n)
        return 0;

    if (k == 0 || k == n)
        return 1;

    return nCr(n - 1, k - 1) + nCr(n - 1, k);
}

int main() {
    int n = 433, k = 33;
    cout << "Value of C(" << n << ", " << k << ") is " << nCr(n, k) << endl;

    return 0;
}
*/

//nCr=n-1Cr+n-1Cr-1
#include<iostream>
#include<vector>
using namespace std;

int nCrModp(int n, int r, int p){

if(r>n-r)
r=n-r;

vector<vector<int>>C(n+1,vector<int>(r+1,0));

for(int i=0;i<=n;i++)
C[i][0]=1;

for(int i=1;i<=n;i++)
for(int j=1;j<=r&&j<=i;j++)
//nCj=(n-1)Cj+(n-1)C(j-1)
C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;

return C[n][r];
}
int main() {
    int n = 100, r = 2, p = 13;
    std::cout << "Value of nCr % p is " << nCrModp(n, r, p) << std::endl;
    return 0;
}