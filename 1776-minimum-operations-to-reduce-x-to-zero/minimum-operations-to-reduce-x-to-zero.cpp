class Solution {
public:
    int minOperations(vector<int>&nums,int x){
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        int mini=INT_MAX;
        int l=0,cur=0;
        for(int r=0;r<nums.size();r++){
            cur+=nums[r];
            while(sum-x<cur && l<=r){
                cur-=nums[l];
                l++;
            }
            if(sum-cur==x){
                int rem=nums.size()-(r-l+1);
                mini=min(mini,rem);
            }
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};