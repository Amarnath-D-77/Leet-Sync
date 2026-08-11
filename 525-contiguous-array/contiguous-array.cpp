class Solution {
public:
    int findMaxLength(vector<int>&nums){
        int n=nums.size();
        unordered_map<int,int>um;
        um[0]=-1;
        int cur=0,maxi=0;
        for(int i=0;i<n;i++){
            cur+=(nums[i]==1)?1:-1;
            if(um.contains(cur)){
              maxi=max(maxi,i-um[cur]);
            }
            else{
                um[cur]=i;
            }
        }
   return maxi;
    }
};