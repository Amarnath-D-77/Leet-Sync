class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>&nums,int limit){
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<int>ans(n);
      int i=0,j;
      while(i<n){
        j=i+1;
        vector<int>ind;
        while(j<n && v[j].first-v[j-1].first<=limit){
            j++;
        }
        for(int idx=i;idx<j;idx++){
            ind.push_back(v[idx].second);
        }
        sort(ind.begin(),ind.end());
        for(int k=0;k<ind.size();k++){
            ans[ind[k]]=v[i+k].first;
        }
        i=j;
      }
      return ans;
    }
};