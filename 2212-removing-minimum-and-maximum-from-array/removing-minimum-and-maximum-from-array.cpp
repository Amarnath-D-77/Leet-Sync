class Solution {
public:
    int minimumDeletions(vector<int>& nums){
      int n=nums.size();
      int in,j,maxi=INT_MIN,mini=INT_MAX;
      for(int i=0;i<n;i++){
        int x=nums[i];
         if(maxi<x){
            maxi=x;
            in=i;
         }
         if(mini>x){
            mini=x;
            j=i;
         }
      }
      int ans=max(in,j)+1;
      int ans1=n-min(in,j);
      int ans2=min(in,j)+1+n-max(in,j);
      cout<<ans<<" "<<ans1<<" "<<ans2<<endl;
      return min({ans,ans1,ans2});
    }
};