class Solution {
public:
    int minCost(int n,vector<int>&cuts){
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m=cuts.size()-2;
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));

    for(int i=m;i>=1;i--){
        for(int j=i;j<=m;j++){
            int mini=INT_MAX;
            for(int k=i;k<=j;k++){
         int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
         mini=min(cost,mini);
            }
            dp[i][j]=mini;
        }
    }       
       return dp[1][m]; 
    }
};