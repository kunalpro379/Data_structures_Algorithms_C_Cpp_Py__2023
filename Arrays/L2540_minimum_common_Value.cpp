class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, k = 0;

    while (i < nums1.size() && k < nums2.size()) {
        if (nums1[i] < nums2[k]) {
            i++;
        } else if (nums1[i] > nums2[k]) {
            k++;
        } else {
            return nums1[i];
        }
    }

    return -1;
}

};
