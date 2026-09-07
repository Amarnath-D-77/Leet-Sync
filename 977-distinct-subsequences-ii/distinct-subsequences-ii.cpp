/*
  similar problem to that of number of unique good subsequences
*/
class Solution {
public:
    int distinctSubseqII(string s){
        int MOD=1e9+7;
        vector<int>dp(26,0);
        
        for(char c:s){
            int tot=0;
            for(int x:dp){
                tot=(tot+x)%MOD;
            }
            dp[c-'a']=(tot+1)%MOD;
        }
        int ans=0;
        for(int x:dp){
            ans=(ans+x)%MOD;
        }
        return ans;
    }
};