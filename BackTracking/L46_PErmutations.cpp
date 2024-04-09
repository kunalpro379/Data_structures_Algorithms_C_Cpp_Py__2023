class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
               vector<vector<int>> res;
        vector<int> current;
        vector<bool>used(nums.size(),false);
                backtrack(nums, current, res, used);
        return res;

    }
    void backtrack(vector<int>& nums,vector<int>& current,
    vector<vector<int>>& res,  vector<bool>& used){
        if(current.size()==nums.size()){
            res.push_back(current);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                used[i]=true;
                    current.push_back(nums[i]);
                    backtrack(nums,current,res,used);
                    current.pop_back();
                used[i]=false;
            }
        }
    }
};