class Solution{
public:
    long long maxDifference(vector<int>&nums){
        int n=nums.size();
        vector<long long>dp(n+1);
        for(int i=n-1;i>=0;i--){
           long long s1=nums[i];
           long long take=(s1%3==0)?(s1-dp[i+1]):(s1+dp[i+1]);
           long long maxi=take;
           if(i+1<n){
           long long s2=(long long)nums[i]+nums[i+1];
           long long take1=(s2%3==0)?(s2-dp[i+2]):(s2+dp[i+2]);
            maxi=max(maxi,take1);
           }
           dp[i]=maxi;
        }
        return dp[0];
    }
};