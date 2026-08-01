class Solution {
public:
    int findMin(vector<int>&nums){
        int low=0,high=nums.size()-1;
        int maxi=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[high]){
                maxi=min(maxi,nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
               maxi=min(maxi,nums[low]);
               low=mid+1;
            }
            else{
                maxi=min(maxi,nums[mid]);
                high=mid-1;
            }
        }
         return maxi;
    }
};