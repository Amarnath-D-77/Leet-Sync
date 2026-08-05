class Solution {
public:
    vector<int>remainingMethods(int n,int k,vector<vector<int>>&invocations){
        vector<vector<int>>adj(n);
        for(auto x:invocations){
         adj[x[0]].push_back(x[1]);
        }
        vector<bool>suspicious(n,false);
        suspicious[k]=true;
        queue<int>q;
        q.push(k);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int x:adj[cur]){
                if(!suspicious[x]){
                    suspicious[x]=true;
                    q.push(x);
                }
            }
        }
        bool check=true;
        for(auto x:invocations){
         int u=x[0];
         int v=x[1];
         if(!suspicious[u] && suspicious[v]){
            check=false;
            break;
         }
        }
        vector<int>ans;
        if(!check){
         for(int i=0;i<n;i++){
            ans.push_back(i);
         }
        }
        else{
            for(int i=0;i<n;i++){
                if(!suspicious[i]){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};