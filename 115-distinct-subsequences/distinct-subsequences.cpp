/*
OBSERVATION:
           recursion logic:

            i->index for s
            j->index for t
          base case:
                   if the index for reaches 0 for string t ,then subseq is formed
                   so we put 1 
        if char dont match:
                         we keep the j same and look for matching char in the remaining 
                         string 
        if char match:
                    case 1:
                          we proceed to match j-1 th index to charcters from i-1 to 0 in the main string 
                    case 2:
                          we try to match the same j to i-1 charcters in the main 
                          string because a duplicate may be residing in the main 
                          string

    Because we are counting distinct subsequences we have to look for the
    duplicate charcters in the main case so we use two cases                  
*/
class Solution {
public:
    int numDistinct(string s,string t){
        int n=s.size();
        int m=t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int j=0;j<=n;j++){
            dp[j][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
       return (int)dp[n][m];
    }
};