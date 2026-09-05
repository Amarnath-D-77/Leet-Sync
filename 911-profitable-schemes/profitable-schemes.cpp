/*
  normal knapsack 
*/
class Solution {
public:
    int mod=1e9+7;
    int rec(int prof_ob,int idx,int rem,int n,int minProfit,vector<int>&group,vector<int>&profit,
    vector<vector<vector<int>>>&dp){
        prof_ob=min(prof_ob,minProfit);
        if(idx==group.size()){
            if(prof_ob>=minProfit){
                return 1;
            }
            return 0;
        }
        if(dp[idx][rem][prof_ob]!=-1){
            return dp[idx][rem][prof_ob];
        }
        int not_take=rec(prof_ob,idx+1,rem,n,minProfit,group,profit,dp);
        int take=0;
        if(rem-group[idx]>=0){
           take=rec(prof_ob+profit[idx],idx+1,rem-group[idx],n,minProfit,group,profit,dp);
        }
        dp[idx][rem][prof_ob]=(take+not_take)%mod;
        return dp[idx][rem][prof_ob];
    }
    int profitableSchemes(int n,int minProfit,vector<int>&group,vector<int>&profit){
        int m=group.size();
        int prof_ob=0;
        int idx=0;
        int rem=n;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        int ans=rec(prof_ob,idx,rem,n,minProfit,group,profit,dp);
        return ans;
    }
};