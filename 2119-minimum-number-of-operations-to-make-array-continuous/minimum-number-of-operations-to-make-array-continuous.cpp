class Solution {
public:
    int minOperations(vector<int>&nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int m=nums.size();
        int j=0;
        int mini=n;
        for(int i=0;i<m;i++){
            int l=nums[i];
            while(j<m && nums[j]-nums[i]<=n-1){
                j++;
            }
        mini=min(mini,n-(j-i));
        }
      return mini;
    }
};