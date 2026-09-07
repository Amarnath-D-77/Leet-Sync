class Solution {
public:
    bool isMatch(string s,string p){
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=1;
        for(int i=2;i<=m;i++){
            if(p[i-1]=='*'){
            dp[0][i]=dp[0][i-2];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                  //CASE1: zero occurence of the preceding element
                  //       zero occurence means it also absorbs the 
                  //       the star and also the preceding character  
                  dp[i][j]=dp[i][j-2];
                  // j-2 can never go out of bounds because
                // the star will always have a preceding character,there will
                //never be "" before a star 
                  
                  //CASE 2: one or more occurenece
                  if(p[j-2]==s[i-1] || p[j-2]=='.'){
                     // dp[i][j] denotes the zero occurence which is calc above
                     // dp[i-1][j]  keeps the star active and checks the if it matches
                     // for next next characters 
                    dp[i][j]=dp[i][j] || dp[i-1][j];
                  }
                   
                }
            }
        }
       return dp[n][m];
    } 
};