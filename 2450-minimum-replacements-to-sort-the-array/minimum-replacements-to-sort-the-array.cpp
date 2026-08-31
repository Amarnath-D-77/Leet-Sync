class Solution {
public:
    long long minimumReplacement(vector<int>&nums){
        int n=nums.size();
        int bound=nums[n-1];
        long long ans=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>bound){
              int op=(nums[i]+bound-1)/bound;
              ans+=(long long)op-1;
              bound=nums[i]/op;
            }
            else{
                bound=nums[i];
            }
        }
        return ans;
    }
};