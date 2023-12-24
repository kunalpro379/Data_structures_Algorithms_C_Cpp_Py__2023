class Solution {
public:
void subsets( vector<int>&current,vector<int>& nums,int start, vector<vector<int>>&ans){
if(start==nums.size()){
    ans.push_back(current);
    return;


}

//choose 
current.push_back(nums[start]);
subsets(current,nums,start+1,ans);

//dont choose
current.pop_back();
subsets(current,nums,start+1,ans);



}


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>current;
        vector<vector<int>>ans;
        subsets(current,nums,0,ans);
        return ans;

    }
};