#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

class Solution {
public:
    double maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        double finalVal = 0.0; 
        int remainingSpace = truckSize;

        for (const auto& box : boxTypes) {
            if (remainingSpace >= box[0]) {
                finalVal += box[0] * box[1];
                remainingSpace -= box[0];
            } else {
                finalVal += remainingSpace * box[1];
                break; 
            }
        }

        return finalVal;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> boxTypes = {{5,10},{2,5},{4,7},{3,9}};
    int truckSize = 10;
    double maxUnits = solution.maximumUnits(boxTypes, truckSize);
    cout << "Maximum units that can be loaded: " << maxUnits << endl;
    return 0;
}
