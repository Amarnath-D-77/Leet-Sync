class Solution {
public:
    long long maxScore(vector<int>&nums1,vector<int>&nums2,int k){
      priority_queue<long long,vector<long long>,greater<long long>>pq;
       vector<pair<long long,long long>>v;
       for(int i=0;i<nums1.size();i++){
        v.push_back({nums2[i],nums1[i]});
       }
       sort(v.rbegin(),v.rend());
       long long cur=0;
       long long maxi=0;
       for(int i=0;i<v.size();i++){
        pq.push(v[i].second);
        cur+=v[i].second;
        if(pq.size()>k){
            cur-=pq.top();
            pq.pop();
        }
        if(pq.size()==k){
          long long curr=v[i].first*cur;
          maxi=max(maxi,curr);
        }
       }
       return maxi;
    }
};