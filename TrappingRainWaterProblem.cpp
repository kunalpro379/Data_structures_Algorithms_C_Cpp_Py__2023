//Two pointers Tecqnique

//Two pointers Tecqnique
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.








#include<vector>

  class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
        
        if (n <= 2) {
            return 0;
        }

        vector<int> leftmax(n, 0);
    vector<int> rightmax(n, 0);

        leftmax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        rightmax[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; --j) {
            rightmax[j] = max(rightmax[j + 1], height[j]);
        }

        int trappedWater = 0;
        for (int k = 0; k < n; ++k) {
            trappedWater += max(0, std::min(leftmax[k], rightmax[k]) - height[k]);
        }

        return trappedWater;
    }
    
};

