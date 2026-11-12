class Solution {
public:
    int longestMonotonicSubarray(vector<int>&nums){
        int i=0,j,maxi=1;
        for(j=1;j<nums.size();j++){
            if(nums[j]>=nums[j-1]){
                maxi=max(maxi,j-i);
                i=j;
            }
         }
            maxi=max(maxi,j-i);
        int mini=1;
        i=0;
         for(j=1;j<nums.size();j++){
            if(nums[j]<=nums[j-1]){
                mini=max(mini,j-i);
                i=j;
            }
         }
          mini=max(mini,j-i);
        
         return max(mini,maxi);
    }
};