class Solution{
public:
    int maxSelectedElements(vector<int>&nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=nums[n-1];
        int ans=1;
        vector<int>dp(maxi+2,0);
        for(int i=0;i<n;i++){
            int x=nums[i];
            dp[x+1]=dp[x]+1;
            dp[x]=dp[x-1]+1;
            int cur=max(dp[x+1],dp[x]);
            ans=max(ans,cur);
        }
        return ans;
    }
};