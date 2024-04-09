#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, 1);

        int leftProd = 1;
        int rightProd = 1;

        for (int i = 0; i < n; i++) {
            result[i] *= leftProd;
            leftProd *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProd;
            rightProd *= nums[i];
        }

        return result;
    }
};
