class Solution {
public:
    double mincostToHireWorkers(vector<int>&quality,vector<int>&wage,int k){
        vector<pair<double,int>>v;
        for(int i=0;i<wage.size();i++){
            v.push_back({(double)wage[i]/quality[i],quality[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int cur=0;
        double maxi=DBL_MAX;
        for(int i=0;i<v.size();i++){
            double ratio=v[i].first;
            int    qual=v[i].second;
            cur+=qual;
            pq.push(qual);
            if(pq.size()>k){
                cur-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                maxi=min(maxi,cur*ratio);
            }
        }
    return maxi;      
    }
};