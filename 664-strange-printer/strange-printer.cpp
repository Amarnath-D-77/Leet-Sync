class Solution {
public:
    int rec(vector<vector<vector<int>>>&dp,vector<char>&box,vector<int>ocur,int i,int j,int extra){
        if(i>j){
            return 0;
        }
        if(dp[i][j][extra]!=INT_MAX){
            return dp[i][j][extra];
        }
        int ans=1+rec(dp,box,ocur,i+1,j,0);
        for(int k=i+2;k<=j;k++){
         if(box[i]==box[k]){
            ans=min(ans,rec(dp,box,ocur,i+1,k-1,0)+rec(dp,box,ocur,k,j,0));
         }
        }
        return dp[i][j][extra]=ans;
    }
    int strangePrinter(string s){
        int n=s.size();
        vector<char>box;
        vector<int>ocur;
        int cnt=1;
        for(int i=0;i<n-1;i++){
          if(s[i]==s[i+1]){
            cnt++;
          }
          else{
            box.push_back(s[i]);
            ocur.push_back(cnt);
            cnt=1;
          }
        }
        box.push_back(s[n-1]);
        ocur.push_back(cnt);
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,INT_MAX)));
    int ans=rec(dp,box,ocur,0,box.size()-1,0);
    return ans;
    }
};