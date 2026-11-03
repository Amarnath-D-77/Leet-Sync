class Solution {
public:
    long long maxSpending(vector<vector<int>>&values){
        int m=values.size(),n=values[0].size();
        vector<int>v;
        while(true){
            int mini=INT_MAX,idx=-1;
            for(int i=0;i<m;i++){
                if(!values[i].empty() && mini>values[i].back()){
                   mini=values[i].back();
                   idx=i;
                }
            }
            if(idx==-1){
                break;
            }
            values[idx].pop_back();
            v.push_back(mini);
        }
        long long  cnt=1;
        long long ans=0;
        for(int i=0;i<v.size();i++){
        ans+=cnt*v[i];
        cnt++;
        }
       return ans;
    }
};