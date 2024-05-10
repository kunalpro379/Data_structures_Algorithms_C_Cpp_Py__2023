class Solution {
public:
   int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int >m;
        m[0]=1;//dont forget this
        int prefSum=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            prefSum+=nums[i];
            if(m.count(prefSum-k)){
                total+=m[prefSum-k];
                m[prefSum]++;
            }
            else{
                m[prefSum]++;
            }
        }return total;
        // unordered_map<int, int> prefixSumCount;  
        // prefixSumCount[0] = 1;  
        // int prefixSum = 0;
        // int count = 0;

        // for (int num : nums) {
        //     prefixSum += num;

        //     if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
        //         count += prefixSumCount[prefixSum - k];
        //     }

        //     prefixSumCount[prefixSum]++;
        // }

        // return count;
    }
};