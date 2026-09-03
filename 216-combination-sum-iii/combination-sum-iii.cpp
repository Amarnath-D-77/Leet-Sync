class Solution {
public:
    void rec(int st,vector<vector<int>>&v,int k,int n,vector<int>&cur){
        if(n==0 && cur.size()==k){
            v.push_back(cur);
            return;
        }
        for(int i=st;i<10;i++){
            if(n-i>=0 && cur.size()<=k){
                cur.push_back(i);
                rec(i+1,v,k,n-i,cur);
                 cur.pop_back();
            }
        }
    }
    vector<vector<int>>combinationSum3(int k, int n){
        vector<vector<int>>v;
        vector<int>cur;
        rec(1,v,k,n,cur);
        return v;
    }
};