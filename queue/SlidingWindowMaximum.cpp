
#include<iostream>
#include<queue>
using namespace std;
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int n=nums.size();
        if(n<k){
cout<<"Invalid";
}
int max_sum=0;
for(int i=0;i<k;i++)
max_sum+=nums[i];
int windowsum=max_sum;

for(int i=k;i<n;i++){
windowsum+=nums[i]-nums[i-k];

max_sum=max(max_sum,windowsum);

     }
return max_sum;

    }
    
};
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n =nums.size();
      vector<int>result;
      if(n==0||k==0){
          return result;//
      }
      deque<int>dq;
      //fisrt window
    for(int i=0;i<k;i++){
        while(!dq.empty() && nums[i]>nums[dq.back()]){
            dq.pop_back();
        }
    dq.push_back(i);
    }
    result.push_back(nums[dq.front()]);
    for(int i=k;i<n;i++){
        while(!dq.empty()&&dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty()&&nums[i]>nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        result.push_back(nums[dq.front()]);
    }

    return result;

    }
};