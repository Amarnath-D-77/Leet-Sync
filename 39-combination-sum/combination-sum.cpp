class Solution {
public:

   void rec(int s,int tar,vector<vector<int>>&ans,vector<int>&candidates,vector<int>&cur){ 
        if(tar==0){
            ans.push_back(cur);
        }
        for(int i=s;i<candidates.size();i++){
            if(tar-candidates[i]>=0){
              cur.push_back(candidates[i]);
              rec(i,tar-candidates[i],ans,candidates,cur);
              cur.pop_back();
            }
        }     
    }
    vector<vector<int>> combinationSum(vector<int>&candidates,int target){
        vector<vector<int>>ans;
        vector<int>cur;
        rec(0,target,ans,candidates,cur);
        return ans;
    }
};