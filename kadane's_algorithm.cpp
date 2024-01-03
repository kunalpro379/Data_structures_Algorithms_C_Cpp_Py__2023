#include<iostream>
using namespace std;

//largest sum continuous subarray

//psudo code 
/*
initialize :
maxSoFar=INT_MIN
maxEndingHere=0

loop for each element of the array
maxEndingHere-maxEndingHere+A[i]
if(maxSoFar<maxEndingHere)
maxSoFar=maxEndingHere

if(maxEndingHere<0)
maxEndingHere=0

return maxSoFar

*/

#define INT_MIN 1999999999;
int maxSubArrSum(int A[],int Size)
{
int maxSoFar=-INT_MIN;
int maxEndingHere=0;

    for(int i=0;i<Size;i++){
            maxEndingHere=maxEndingHere+A[i];
            if(maxSoFar<maxEndingHere)
                maxSoFar=maxEndingHere;
            if(maxEndingHere<0)
                maxEndingHere=0;
    }
return maxSoFar;

}
int main(){
int A[]={-2,-343,-23,3,32,222,98,-23,344,-330,78};
int n=sizeof(A)/sizeof(A[0]);
int maxSum=maxSubArrSum(A,n);
cout<<"Maximum sum of subarray is "<<maxSum<<endl;
}