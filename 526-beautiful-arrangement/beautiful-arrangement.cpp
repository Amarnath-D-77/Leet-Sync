class Solution {
public:
    void backtrack(int n,int cur,vector<bool>&vis,int &ans){
        if(cur>n){
            ans++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i] && (i%cur==0 || cur%i==0)){
                vis[i]=true;
                backtrack(n,cur+1,vis,ans);
                vis[i]=false;
            }
        }    
    }
    int countArrangement(int n){
        int ans=0;
        vector<bool>vis(n+1,false);
        backtrack(n,1,vis,ans);
        return ans;
    }
};