class Solution {
public:
    long long minCost(vector<int>&nums){
        int n=nums.size();
        long long ans=nums[0]+nums[n-1];
        sort(nums.begin()+1,nums.begin()+n-1);
        for(int i=1;i<n-2;i+=2){
         if(nums[i]+nums[i+1]<0){
            ans+=nums[i]+nums[i+1];
         }
        } 
        return ans;
    }
};