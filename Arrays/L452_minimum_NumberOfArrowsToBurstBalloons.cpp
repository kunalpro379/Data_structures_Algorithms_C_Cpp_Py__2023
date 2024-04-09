class Solution {
public:
    // int findMinArrowShots(vector<vector<int>>& points) {
    //     auto comp=[](vector<int>&a, vector<int>&b){
    //         return a[1]<b[1];
    //     };sort(points.begin(), points.end(),comp);
    //     int arrowPos=points[0][1], arrowshot=1;
    //     for(int i=1;i<points.size();i++){
    //         if(points[i][0]<=arrowPos){continue;}
    //         arrowPos=points[i][1];
    //         arrowshot++;
    //     }
    //     return arrowshot;
    // }

    int findMinArrowShots(vector<vector<int>>& points) {
  
if(points.empty()) return 0;
int minEnd=points[0][1];
int maxEnd=points[0][1];

for(const auto & point: points){
    minEnd=min(minEnd, point[1]);
    maxEnd=max(maxEnd,point[1]);
}
int arrows=1;
int end=minEnd;
for(const auto&point: points){
    if(point[0]>end){
        arrows++;
        end=point[1];
    }
}
return arrows;
    }
};