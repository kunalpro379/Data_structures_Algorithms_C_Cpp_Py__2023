class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>numCounts;
        vector<int>res;

        for(int &num:nums1){
            numCounts[num]++;
        }
        for(int &num:nums2){
            if(numCounts.find(num)!=numCounts.end()&&numCounts[num]>0){
                res.push_back(num);
                numCounts[num]--;
            }

        }
        return res;
    }
};