class Solution {
public:
    int maxArea(vector<int>& height) {
        int MaxA=0;
        int left=0;
        int right=height.size()-1;

        while(left<right){
            int currentA=(right-left)* min(height[left], height[right]);
            MaxA=max(MaxA, currentA);
            if(height[left]<height[right])
            left++;

            else
            right--;

        }
    return MaxA;
    }
};