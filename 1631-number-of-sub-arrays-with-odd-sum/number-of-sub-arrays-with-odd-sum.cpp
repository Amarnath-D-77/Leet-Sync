class Solution {
public:
    int numOfSubarrays(vector<int>&arr){
        int n=arr.size();
        int MOD=1e9+7;
        long long tot=(1LL*n*(n+1))/2;
        long long cur=0,ans=0;
        int k=2;
        unordered_map<int,int>um;
        um[0]=1;
        for(int i=0;i<n;i++){
            cur+=arr[i];
            int rem=(cur%k +k)%k;
            if(um.find(rem)!=um.end()){
                ans+=um[rem];
            }
             um[rem]++;
        }
         return (tot-ans)%MOD;
    }
};