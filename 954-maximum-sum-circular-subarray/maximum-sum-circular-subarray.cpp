/*
OBSERVATION:
           EDGE CASE:
                    if all the no are negative then min_kadane would be the whole array 
                    tot-min_kadane results in 0 so it will output 0 ,so max_kadande stores the single largest negative no ,so we return max_kadane
          1.by finding the min subbarray we can minus that from the tot 
          sum to get the circular maximum subbarray( because in wrapping subbarrays
           only a piece of numbers will be cut off so eveythgin will be intact 
           except the min ,when subtracted it gives the largest wrapping subbary )

          2.[-5,10,-5], if we use only tot-min we only get the largest wrapping subary 
          but if use normal kadane we can find the largest subray sum 
           answer->max(max_kadane,tot-min_kadane);
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>&nums){
      int n=nums.size();
      int tot=0;
      int cur_max=0;
      int maxi=nums[0];
      int cur_min=0;
      int mini=nums[0];
      for(int i=0;i<n;i++){
        tot+=nums[i];
        cur_max=max(nums[i]+cur_max,nums[i]);
        maxi=max(maxi,cur_max);
        cur_min=min(nums[i],cur_min+nums[i]);
        mini=min(mini,cur_min);
      }
      if(maxi<0){
        return maxi;
      }
  return max(maxi,tot-mini);
    }
};