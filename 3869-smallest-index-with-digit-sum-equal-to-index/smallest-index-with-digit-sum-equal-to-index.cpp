class Solution {
public:
    int smallestIndex(vector<int>&nums){
     for(int i=0;i<nums.size();i++){
        string s=to_string(nums[i]);
        int cur=0;
        for(char c:s){
          cur+=c-'0';
        }
        if(cur==i){
            return i;
        }
     }     
     return -1;   
    }
};