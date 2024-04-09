class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int>nums1_set(nums1.begin(), nums1.end());
                unordered_set<int>nums2_set(nums2.begin(), nums2.end());
                    vector<int>result;
                for(auto &num : nums1_set){
                            if(nums2_set.count(num)>0){
                                result.push_back(num);
                            }
                }
            return result;

    }
};