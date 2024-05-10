#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        /////////////////////brute force O(n cube)
    //     int total=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //              int sum=0;
    //              for(int k=i;k<=j;k++){
    //                  sum+=arr[k];
    //              }
    //              if(sum==0){
    //                  total++;
    //              }
    //         }
    //     }return total;
    
    //  O(n sq)
    // int total=0;
    // for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=arr[j];
    //         if(sum==0){
    //             total++;
    //         }
    //     }
    // }return total;
    
    //optimized prefix sum approach
    
    long long int total=0;
    unordered_map<long long int, long long int >Umap;
    long long int prefixSum=0;
    Umap[0]=1;
    
    for(int i=0;i<n;i++){
        prefixSum+=arr[i];
        if(Umap.count(prefixSum)){
            total+=Umap[prefixSum];
            Umap[prefixSum]++;
        }else{
            Umap[prefixSum]=1;
        }
    }
    return total;
    
  
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends