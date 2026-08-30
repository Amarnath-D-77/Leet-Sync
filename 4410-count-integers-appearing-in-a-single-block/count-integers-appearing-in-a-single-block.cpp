class Solution {
public:
    int countSpecialIntegers(vector<int>&nums){
        unordered_map<int,int>um;
        for(int x:nums){
            um[x]++;
        }
        int i=0,j,cnt=0;
        for(j=0;j<nums.size();j++){
            if(nums[i]!=nums[j]){
               int len=j-i;
               if(len==um[nums[i]]){
                cnt++;
               }  
              i=j;
            }
        }
        int len=j-i;
               if(len==um[nums[i]]){
                cnt++;
               }  
        return cnt;
    }
};