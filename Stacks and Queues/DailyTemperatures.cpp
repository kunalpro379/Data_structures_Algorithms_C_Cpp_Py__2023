class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       vector<int>ans(temperatures.size(),0);
       stack<int>indexStack;
       for(int i=0;i<temperatures.size();i++)
       {
        while(!indexStack.empty()&& temperatures[i]>temperatures[indexStack.top()]){
            int prevInd=indexStack.top();
            indexStack.pop();
            ans[prevInd]=i-prevInd;
        }
        indexStack.push(i);
       } 
       return ans;
    }
};