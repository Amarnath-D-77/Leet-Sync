class Solution {
public:
    void rec(int start,vector<int>&candidates,int tar,vector<vector<int>>&v,vector<int>&ans){
        if(tar==0){
            v.push_back(ans);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]){
                continue;
            }
            if(tar-candidates[i]>=0){
               ans.push_back(candidates[i]);
               rec(i+1,candidates,tar-candidates[i],v,ans);
               ans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>&candidates,int target){
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>v;
        vector<int>ans;
        rec(0,candidates,target,v,ans);
        return v;
    }
};