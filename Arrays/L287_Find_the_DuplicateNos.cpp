class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>numFreq;
        for(int i=0;i<nums.size();i++){
            numFreq[nums[i]]++;
            if(numFreq[nums[i]]>1){
                    return nums[i];
            }
        }
        return -1;

    }
};