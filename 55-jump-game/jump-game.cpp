class Solution{
public:
    bool canJump(vector<int>&nums){
        int maxi=nums[0]+1;
        for(int i=1;i<nums.size();i++){
            if(maxi>=i+1){
                maxi=max(maxi,nums[i]+i+1);
            }
            else{
                return false;
            }
        }
        return true;
    }
};