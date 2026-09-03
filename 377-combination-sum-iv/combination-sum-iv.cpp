class Solution {
public:
  
    int rec(vector<int>&dp,int n,vector<int>&nums){
        if(dp[n]!=-1){
            return dp[n];
        }
        int ways=0;
        for(int i=0;i<nums.size();i++){
            if(n-nums[i]>=0){
            ways=ways+rec(dp,n-nums[i],nums);
            }
            else{
                break;
            }
        }
        dp[n]=ways;
        return dp[n];
    }
    int combinationSum4(vector<int>&nums,int target){
        sort(nums.begin(),nums.end());
        vector<int>dp(target+1,-1);
        dp[0]=1;
        return rec(dp,target,nums);
    }
};