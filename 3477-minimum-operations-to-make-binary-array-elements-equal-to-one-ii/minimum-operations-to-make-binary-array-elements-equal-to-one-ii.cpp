class Solution {
public:
    int minOperations(vector<int>&nums){
        int n=nums.size();
        int cnt=0;
        int flips=0;
        for(int i=0;i<n;i++){
            if(nums[i]==(cnt%2)){
              cnt++;
              flips++;
            }
        }
        return flips;
    }
};