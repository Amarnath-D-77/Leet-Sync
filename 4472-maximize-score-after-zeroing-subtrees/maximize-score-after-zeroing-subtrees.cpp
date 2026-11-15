class Solution {
public:
    int dfs(int node,vector<vector<int>>&child,vector<int>&op,vector<int>&score){
        if(child[node].empty()){
            return score[node];
        }
        int sum_of_parent_and_child_subtree=score[node];
        int mini_child_subtree=1e9;
        for(int v:child[node]){
            int val=dfs(v,child,op,score);
             sum_of_parent_and_child_subtree+=val;
             if(mini_child_subtree>val){
                mini_child_subtree=val;
             }
        }
        if(op[node]==0){
            if(mini_child_subtree<0){
                return sum_of_parent_and_child_subtree-mini_child_subtree;
            }
            return sum_of_parent_and_child_subtree;
        }
        else{
            return sum_of_parent_and_child_subtree-mini_child_subtree;
        }
    }
    int maxScore(vector<int>&parent,vector<int>&op,vector<int>&score){
        int n=parent.size();
        vector<vector<int>>child(n);
        for(int i=0;i<n;i++){
            if(parent[i]!=-1){
            child[parent[i]].push_back(i);
            }
        }
        return dfs(0,child,op,score);
    }
};