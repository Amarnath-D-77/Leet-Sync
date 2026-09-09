class Solution {
public:
    int rec(int i,int j,vector<vector<int>>&dp,vector<int>&nums){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi=0;
        for(int k=i;k<=j;k++){
          int cost=nums[i-1]*nums[k]*nums[j+1]+rec(i,k-1,dp,nums)+rec(k+1,j,dp,nums);
          maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>&nums){
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return rec(1,n-2,dp,nums);
    }
};