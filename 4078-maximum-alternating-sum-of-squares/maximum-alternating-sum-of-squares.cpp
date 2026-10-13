class Solution {
public:
    long long maxAlternatingSum(vector<int>&nums){
        for(int i=0;i<nums.size();i++){
           nums[i]=abs(nums[i]);
        }
       sort(nums.begin(),nums.end());
       int i=0,j=nums.size()-1;
       long long  ans=0;
       while(i<=j){
        if(i==j){
            ans+=(nums[j]*nums[j]);
        }
        else{
            ans+=(nums[j]*nums[j]);
           ans-=(nums[i]*nums[i]);
        }
        i++;
        j--;
       } 
       return ans;
    }
};