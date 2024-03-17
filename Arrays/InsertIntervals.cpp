class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>>res;
         int i=0;

         while(i<intervals.size()&&intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i++]);
         }
         while(i<intervals.size()&&intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0], intervals[i][0]);
            newInterval[1]=max(newInterval[1], intervals[i][1]);
            i++;
         }
        res.push_back(newInterval);
        res.insert(res.end(), intervals.begin()+i, intervals.end());
         return res;       
    }
};