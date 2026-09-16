class Solution {
public:
    int minCut(string s){
        int n=s.size();
        vector<vector<bool>>palin(n,vector<bool>(n,false));
        vector<int>dp(n,0);
        for(int j=0;j<n;j++){
            int mini=j;
            for(int i=0;i<=j;i++){
                if(s[i]==s[j] && (j-i+1<=2 || palin[i+1][j-1])){
                    palin[i][j]=true;
                    if(i==0){
                     mini=0;
                    }
                    else{
                      mini=min(mini,dp[i-1]+1);  
                    }
                }
                dp[j]=mini;
            }
        }
     return dp[n-1];
    }
};