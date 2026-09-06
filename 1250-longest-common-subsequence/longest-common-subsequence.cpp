/*
OBSERVATION:
      1.in this dp[i][j] represents lcs of two strings upto i and j in both the strings it builds from the first index and keeps on building and finally reaches the end 
      2. if char matches we do 1+diag(up,left) because upto i we found the match character and we find behing this whats the maximum longest subsequence and we do 1+..;
      3. if mismatches we do max(dp[i][j-1],dp[i-1][j]), that is nothing but checking by skipping the cur char in both strings 
*/
class Solution {
public:
    int longestCommonSubsequence(string text1,string text2){
       int n=text1.size();
       int m=text2.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       }
       return dp[n][m];
    }
};