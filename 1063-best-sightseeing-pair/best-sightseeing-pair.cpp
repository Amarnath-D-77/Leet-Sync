class Solution {
public:
    int maxScoreSightseeingPair(vector<int>&values){ 
        int n=values.size();
        vector<int>v=values;
        for(int i=0;i<n;i++){
            v[i]-=i;
        }
        vector<int>suf(n);
        suf[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],v[i]);
        }
        int ans=-1;
        for(int i=0;i<n-1;i++){
            ans=max(ans,values[i]+i+suf[i+1]);
        }
        return ans;
    }
};