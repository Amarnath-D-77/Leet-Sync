class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
         int n=nums.size();
        int maxi=1;
        for(int i=0;i<n;){
            int rem=nums[i]%k;
            int j=i;
            while(j<n && nums[j]%k==rem){
                j++;
            }
            int blen=j-i;
            for(int l=blen;l>maxi;l--){
                if(((l-1)*rem)%k==0){
                    maxi=max(maxi,l);
                    break;
                }
            }
            i=j;
        }
        return maxi;
    }
};