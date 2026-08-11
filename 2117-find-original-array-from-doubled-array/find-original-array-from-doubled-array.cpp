class Solution {
public:
    vector<int>findOriginalArray(vector<int>& changed){
        int n=changed.size();
        if(n%2!=0){
            return {};
        }
        sort(changed.begin(),changed.end());
        vector<int>v;
        map<int,int>m;
        for(int x:changed){
            m[x]++;
        }
        for(int i=0;i<n;i++){
           if(m[changed[i]]==0){
            continue;
           }
           if(m[changed[i]*2]==0){
            return {};
           }
           v.push_back(changed[i]);
           m[changed[i]]--;
           m[changed[i]*2]--;
        }
    return v;
    }
};