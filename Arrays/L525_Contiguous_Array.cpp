class Solution {
public:
    int findMaxLength(vector<int>& nums) {
            int n=nums.size();
            unordered_map<int, int>prefSumInd;
            int maxlen=0;
            int sum=0;

            for(int i=0;i<n;i++){
                sum+=(nums[i]==0)?-1:1;
                if(sum==0){maxlen=i+1;}
                //if sum has seen before
                
                if(prefSumInd.find(sum)!=prefSumInd.end())
                    maxlen=max(maxlen,i-prefSumInd[sum]);
                else
                prefSumInd[sum]=i;
            }   
        return maxlen;
    }
};