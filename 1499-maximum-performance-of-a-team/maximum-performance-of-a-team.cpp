class Solution {
public:
    int maxPerformance(int n,vector<int>&speed,vector<int>&efficiency,int k){
        int MOD=1e9+7;
        vector<pair<int,int>>v;
        for(int i=0;i<speed.size();i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
         long long  maxi=LLONG_MIN;
         long long  cur=0;
         priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<v.size();i++){
            int speed=v[i].second;
            int effi=v[i].first;
            pq.push(speed);
            cur+=speed;
            if(pq.size()>k){
                cur-=pq.top();
                pq.pop();
            } 
              maxi=max(maxi,cur*effi);
        }
        return maxi%MOD;
    }
};