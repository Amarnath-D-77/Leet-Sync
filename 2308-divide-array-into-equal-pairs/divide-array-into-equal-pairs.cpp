class Solution {
public:
    bool divideArray(vector<int>&nums){
         int n=nums.size();
         unordered_map<int,int>um;
         for(int i=0;i<n;i++){
            um[nums[i]]++;
         }
         for(auto x:um){
            if(x.second%2!=0){
             return false;
            }
         }
         return true;
    }
};