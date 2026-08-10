class Solution {
public:
    int minSwaps(vector<int>&nums){
      int n=nums.size();
      int k=0;
      for(int x:nums){
         if(x==1){
            k++;
         }
      }
     if(k==0 || k==n){
        return 0;
     }
      int cnt=0;
      for(int i=0;i<k;i++){
        if(nums[i]==1){
         cnt++;
        }
      }
      int ans=k-cnt;
      for(int i=k;i<n+k;i++){
        if(nums[(i-k)%n]==1){
            cnt--;
        }
        if(nums[i%n]==1){
            cnt++;
        }
        ans=min(ans,k-cnt);
        cout<<k-cnt<<endl;
      }
    return ans;
    }
};