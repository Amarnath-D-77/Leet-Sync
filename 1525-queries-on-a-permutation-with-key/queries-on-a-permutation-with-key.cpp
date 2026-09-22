class Solution {
public:
    vector<int> processQueries(vector<int>&queries,int m){
        vector<int>v(m);
        for(int i=1;i<=m;i++){
            v[i-1]=i;
        }
        vector<int>ans;
        for(int x:queries){
            int cur=x;
            auto it=find(v.begin(),v.end(),cur);
            ans.push_back(distance(v.begin(),it));
            v.erase(it);
            v.insert(v.begin(),cur);
        }
        return ans;
    }
};