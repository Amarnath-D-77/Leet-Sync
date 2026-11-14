class Solution {
public:
    int sub(vector<int>&nums,int size){
        int cur=0,i=0,j=0,n=nums.size();
        while(j-i+1<=size){
            cur+=nums[j];
            if(j-i+1==size){
                break;
            }
            j++;
        }
       int mini=INT_MAX;
       if(cur>0){
        mini=cur;
       }
       while(i<n && j+1<n){
         cur-=nums[i];
         i++;
         j++;
         cur+=nums[j];
         if(mini>cur && cur>0)
         mini=cur;
       }
        return mini;
    }
    int minimumSumSubarray(vector<int>&nums,int l,int r){
        int mini=INT_MAX;
        for(int i=l;i<=r;i++){
            mini=min(mini,sub(nums,i));
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};