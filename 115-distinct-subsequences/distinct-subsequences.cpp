/*
OBSERVATION:
           1> if the char matches: 
                    1>we found the char and i-1 ,j-1 
                    2> we can search for another char that mathces j so i-1,j
           1.BASE CASE:
                   1>if the target reaches 0 then the subsequence is found somewhere in the main string so we return 1 ;
                   2>else if the main string reaches 0 and the index in target string is not zero then the target subsequence cannot be made so we return 0 
           2. if we build this bottom up ,we initalize dp[j][0] is 1 because the empty target subseq can be formed from any suffixes of the main string

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