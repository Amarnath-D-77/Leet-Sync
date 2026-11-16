class Solution {
public:
    int numberOfGoodPartitions(vector<int>&nums){
        int n=nums.size(),MOD=1e9+7;
        unordered_map<int,int>um;
        unordered_map<int,int>first_idx;
        unordered_map<int,int>last_idx;
        for(int i=0;i<n;i++){
            first_idx[nums[i]]=-1;
        }
        for(int i=0;i<n;i++){
         int x=nums[i];
            um[x]++;
            if(first_idx[x]==-1){
                first_idx[x]=i;
            } 
            last_idx[x]=i;
        }
        vector<pair<int,int>>v;
        int f=first_idx[nums[0]];
        int l=last_idx[nums[0]];

        v.push_back({f,l});

         for(int i=1;i<n;i++){
            int curf=first_idx[nums[i]];
            int curl=last_idx[nums[i]];
            int prevl=v.back().second;
            if(prevl>curf){
                v.back().second=max(v.back().second,curl);
            }
            else{
                v.push_back({curf,curl});
            }
         }
         int cur=v.size()-1;
         int ans=1,cnt=0;
         while(cnt<cur){
            ans=(ans*2)%MOD;
            cnt++;
         }
         return ans;
    }
};