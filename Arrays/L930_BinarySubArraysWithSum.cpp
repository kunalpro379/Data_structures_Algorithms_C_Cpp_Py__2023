class Solution {
public:
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     int left = 0, right = 0;
    //     int sum = 0, count = 0;

    //     while (right < nums.size()) { // expanding the window
    //         sum += nums[right];

    //         while (left <= right && sum > goal) { // shrinking the window
    //             sum -= nums[left];
    //             left++;
    //         }

    //         if (sum == goal) { // if goals equal count it...
    //             int leftTemp = left;
    //             while (leftTemp <= right && nums[leftTemp] == 0) {
    //                 count++; // counting subarrays
    //                 leftTemp++;
    //             }
    //         }
    //         right++;
    //     }
    //     return count;
    // }

        int numSubarraysWithSum(vector<int>& nums, int goal) {
    int l=0,count=0,res=0;
    for (int r=0;r<nums.size();r++){
        if(nums[r]==1){
            goal--;
            count=0;
        }
        while(goal ==0&& l<=r){//checking  goal achievement 
            goal+=nums[l];
            l++;
            count++;

        }
        while(goal<0){//adjusting window if -ve goal
            goal+=nums[l];
            l++;
        }
        res+=count;
    }
    return res;
    }
};
