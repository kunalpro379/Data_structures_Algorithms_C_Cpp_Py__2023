#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool containsDuplicate_approach1(const vector<int>& nums) {
    unordered_set<int> seen;
    for(int num : nums){
        if(seen.find(num) != seen.end()){
            return true;
        }
        seen.insert(num);
    }
    return false;
}

bool containsDuplicate_approach2(const vector<int>& nums) {
    vector<int> sorted_nums(nums.begin(), nums.end());
    sort(sorted_nums.begin(), sorted_nums.end());
    for (int i = 1; i < sorted_nums.size(); i++) {
        if (sorted_nums[i] == sorted_nums[i - 1]) {
            return true;
        }
    }
    return false;
}

#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        std::vector<pair<int, int>> index_num;

        for (int i = 0; i < nums.size(); i++) {
            index_num.push_back({i, nums[i]});
        }

        std::sort(index_num.begin(), index_num.end());

        for (int i = 1; i < index_num.size(); i++) {
            if (index_num[i].second == index_num[i - 1].second && index_num[i].first - index_num[i - 1].first <= k) {
                return true;
            }
        }

        return false;
    }
};


int main() {
    // Test vectors
    vector<int> nums1 = {1, 2, 3, 4, 5, 1}; 
    vector<int> nums2 = {1, 2, 3, 4, 5};    
    vector<int> nums3 = {1, 2, 3, 4, 5, 1}; 
    
cout << containsDuplicate_approach1(nums1) << endl;
cout << containsDuplicate_approach1(nums2) << endl;


cout << containsDuplicate_approach2(nums1) << endl;
   cout<< containsDuplicate_approach2(nums2) << endl;
cout << containsNearbyDuplicate(nums3, 2) << endl;

    return 0;
}
