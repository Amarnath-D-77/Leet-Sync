class Solution {
public:
    int rec(int idx,int curo,int curz,vector<int>&ones,vector<int>&zer,int m,int n,
    vector<vector<vector<int>>>&dp){
        if(idx==ones.size()){
            if(curz<=m && curo<=n){
                return 1;
            }
            return 0;
        }
        if(dp[idx][curo][curz]!=-1){
            return dp[idx][curo][curz];
        }
        int not_take=rec(idx+1,curo,curz,ones,zer,m,n,dp);
        int take=0;
        if(curo+ones[idx]<=n && curz+zer[idx]<=m){
            take=1+rec(idx+1,curo+ones[idx],curz+zer[idx],ones,zer,m,n,dp);
        }
        dp[idx][curo][curz]=max(take,not_take);
        return dp[idx][curo][curz];
    }
    int findMaxForm(vector<string>&strs,int m, int n){
        int k=strs.size();
        vector<int>ones(k);
        vector<int>zer(k);
        for(int i=0;i<k;i++){
            int cur=strs[i].size();
            int cnt=0;
            for(char c:strs[i]){
                if(c=='1'){
                cnt++;
                }
            }
            ones[i]=cnt;
            zer[i]=cur-cnt;
        }
        int curo=0;
        int curz=0;
        vector<vector<vector<int>>>dp(k,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        int ans=rec(0,curo,curz,ones,zer,m,n,dp);
        return ans-1;
    }
};