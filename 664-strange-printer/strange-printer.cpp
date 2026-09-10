/*
  OBSERVATION:
             similiar to that of remove boxes,but here unlike remove boxes or
             vanya and strings, the cost to print one A or 5 A's is same so 
   in case 1:
             we print the cur contigous block which costs 1 and then we move to i+1->j
             
             rec(dp,box,i+1,k-1)->cost if found by recursion
             rec(dp,box,k,j)->for this since block i and block j merged the cost of i'th 
             block is managed by k th block 

*/
class Solution {
public:
    int rec(vector<vector<int>>&dp,vector<char>&box,int i,int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1+rec(dp,box,i+1,j);
        for(int k=i+2;k<=j;k++){
         if(box[i]==box[k]){
            ans=min(ans,rec(dp,box,i+1,k-1)+rec(dp,box,k,j));
         }
        }
        return dp[i][j]=ans;
    }
    int strangePrinter(string s){
        int n=s.size();
        vector<char>box;
        int cnt=1;
        for(int i=0;i<n-1;i++){
          if(s[i]!=s[i+1]){
            box.push_back(s[i]);
          }
        }
        box.push_back(s[n-1]);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int ans=rec(dp,box,0,box.size()-1);
    return ans;
    }
};