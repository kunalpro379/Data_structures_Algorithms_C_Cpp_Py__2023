#include<iostream>
#include<vector>
#include<deque>
#include<queue>
using namespace std;

class Solution1{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        priority_queue<pair<int, int>> heap;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            while(!heap.empty() && heap.top().second <= (i - k)){
                heap.pop();
            }
            heap.push({nums[i], i});
            if(i >= k - 1){
                res.push_back(heap.top().first);
            }
        }
        return res;
    }
};

class Solution2{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        deque<pair<int, int>> dq;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(!dq.empty() && dq.front().second <= (i - k)){
                dq.pop_front();
            }
            while(!dq.empty() && dq.back().first < nums[i]){
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
            if(i >= k - 1){
                res.push_back(dq.front().first);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution1 sol1;
    Solution2 sol2;

    vector<int> result1 = sol1.maxSlidingWindow(nums, k);
    vector<int> result2 = sol2.maxSlidingWindow(nums, k);

    cout << "Result using Solution1 class:" << endl;
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result using Solution2 class:" << endl;
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
