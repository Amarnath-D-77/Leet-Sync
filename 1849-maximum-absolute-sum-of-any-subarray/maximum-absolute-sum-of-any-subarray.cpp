class Solution {
public:
    int maxAbsoluteSum(vector<int>&nums){
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[0];
        int ans=abs(nums[0]);
        for(int i=1;i<n;i++){
            maxi=max(maxi+nums[i],nums[i]);
            mini=min(mini+nums[i],nums[i]);
            ans=max({ans,abs(mini),abs(maxi)});
        }
    return ans;
    }
};