class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
          int n=nums.size();
        vector<int>pmax(n);
        vector<int>smin(n);
        pmax[0]=nums[0];
        smin[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pmax[i]=max(pmax[i-1],nums[i]);
            smin[n-i-1]=min(smin[n-i],nums[n-i-1]);
        }
     
       for(int i=0;i<n;i++){
           if(pmax[i]-smin[i]<=k){
               return i;
           }
       }
       return -1;
    }
};