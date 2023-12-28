/*Example 1:

Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#include <cmath>
class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
        std::vector<std::pair<int, int>> Ind_Nm;

        for (int i = 0; i < nums.size(); i++) {
            Ind_Nm.push_back({nums[i], i});
        }

        std::sort(Ind_Nm.begin(), Ind_Nm.end());

        for (int i = 0; i < Ind_Nm.size(); i++) {
            for (int j = i + 1; j < Ind_Nm.size(); j++) {
                if (Ind_Nm[j].first - Ind_Nm[i].first <= valueDiff &&
                    std::abs(Ind_Nm[j].second - Ind_Nm[i].second) <= indexDiff) {
                    return true;
                }
                else if (Ind_Nm[j].first - Ind_Nm[i].first > valueDiff) {
                    break;
                }
            }
        }

        return false;
    }
};
