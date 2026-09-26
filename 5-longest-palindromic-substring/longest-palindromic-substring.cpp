/*
OBSERVATION:
         1.For subsequence there will be else case but in substring there will no else case if the characters are not matching 
*/

class Solution {
public:
    string longestPalindrome(string s){
        string s1=s;
        reverse(s1.begin(),s1.end());
        int n=s.size();
        int m=s1.size();
        int maxi=0,end;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==s1[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    int cur=dp[i][j];
                    if(i-cur==n-j){
                      if(maxi<cur){
                        maxi=cur;
                         end=i-1;
                      }
                    }
                }
            }
        }             
      
      return s.substr(end-maxi+1,maxi);
    }
};