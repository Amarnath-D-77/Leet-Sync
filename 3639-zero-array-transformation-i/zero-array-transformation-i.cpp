class Solution {
public:
    bool isZeroArray(vector<int>&nums,vector<vector<int>>&queries){
        int n=nums.size();
        vector<int>diff(n+1,0);
        for(int i=0;i<queries.size();i++){
            diff[queries[i][0]]+=1;
            diff[queries[i][1]+1]-=1;
        }
        int cur=0;
        for(int i=0;i<n;i++){
            cur+=diff[i];
            if(cur<nums[i]){
                return false;
            }
        }
        return true;
    }
};