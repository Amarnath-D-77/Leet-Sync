class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>&intervals){
      vector<pair<pair<int,int>,int>>v;
      int idx=0;
      for(auto x:intervals){
        v.push_back({{x[0],x[1]},idx});
        idx++;
      }
      sort(v.begin(),v.end());
      vector<int>ans(intervals.size(),-1);
      for(int i=0;i<intervals.size();i++){
       int tar=intervals[i][1];
       auto it=lower_bound(v.begin(),v.end(),make_pair(make_pair(tar,INT_MIN),-1));
       if(it!=v.end()){
        ans[i]=it->second;
       }
      }
      return ans;
    }
};