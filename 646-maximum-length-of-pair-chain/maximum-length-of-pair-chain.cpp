class Solution {
public:
    int findLongestChain(vector<vector<int>>&pairs){
        sort(pairs.begin(),pairs.end());
        vector<int>dp;
        for(int i=0;i<pairs.size();i++){
        int val=pairs[i][0];
         auto it=lower_bound(dp.begin(),dp.end(),val);
         int idx=distance(dp.begin(),it);
         if(it==dp.end()){
            dp.push_back(pairs[i][1]);
         }
         else{
           dp[idx]=min(dp[idx],pairs[i][1]);
         }
        }
        return dp.size();
    }
};