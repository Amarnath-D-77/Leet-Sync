class Solution {
public:
    int subarraysDivByK(vector<int>&nums,int k){
         map<int,int>um;
         int ans=0,n=nums.size(),cur=0,rem=0;
         um[0]=1;
         for(int i=0;i<n;i++){
             cur+=nums[i];
             rem=(cur%k +k)%k;
             if(um.find(rem)!=um.end()){
               ans+=um[rem];
             }
             um[rem]++;
         }
       return ans;
    }
};