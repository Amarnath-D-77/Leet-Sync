class Solution{
public:
    int climbStairs(int n,vector<int>&costs){
      
       int dp1=0,dp2=1e9,dp3=1e9;
       for(int i=1;i<=n;i++){
        int mini=dp1+1;
        if(i>=2)mini=min(mini,dp2+4);
        if(i>=3)mini=min(mini,dp3+9);
        int cur=mini+costs[i-1];
      
        dp3=dp2;
        dp2=dp1;
        dp1=cur;
       }
        return dp1;
    }
};