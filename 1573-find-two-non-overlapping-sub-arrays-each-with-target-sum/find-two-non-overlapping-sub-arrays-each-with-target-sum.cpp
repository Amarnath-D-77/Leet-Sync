class Solution {
public:
    int minSumOfLengths(vector<int>&arr,int target){
        int n=arr.size();
        int mini=INT_MAX;
        vector<int>dp(n,INT_MAX);
        int l=0,cur=0;
        for(int r=0;r<n;r++){
           cur+=arr[r];
           while(cur>target && l<=r){
            cur-=arr[l];
            l++;
           }
           if(cur==target){
            if(l>0 && dp[l-1]!=INT_MAX){
             mini=min(mini,dp[l-1]+r-l+1);
            }
            dp[r]=r-l+1;
           }
           if(r>0){
            dp[r]=min(dp[r],dp[r-1]);
           }
        }
    if(mini==INT_MAX){
        return -1;
    }
    return mini;
    }
};