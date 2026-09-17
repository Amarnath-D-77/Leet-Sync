class Solution {
public:
    vector<int>maxSumOfThreeSubarrays(vector<int>&nums,int k){
        int n=nums.size();
        vector<int>dp_idx(n+1,INT_MIN);
        vector<int>dp(n+1,INT_MIN);
        int l=n-1,sum=0,cur_max=-1;
        for(int r=n-1;r>=0;r--){
            sum+=nums[r];
            if(l-r+1>k){
                sum-=nums[l];
                l--;
            }
            if(r<=n-k){
                dp_idx[r]=dp_idx[r+1];
                if(cur_max<=sum){
                    cur_max=sum;
                    dp_idx[r]=r;
                }
              dp[r]=max(dp[r+1],sum);
            }
        }

        vector<int>dp1(n,INT_MIN);
        vector<int>dp1_idx(n,INT_MIN);
        int idx=-1,idx1=-1,idx2=-1;        
        l=0;
        sum=0;
       int  mini=-1;
        cur_max=-1;
        for(int r=0;r<n;r++){
         sum+=nums[r];
         if(r-l+1>k){
                sum-=nums[l];
                l++;
            }
         if(r-l+1==k){
            if(r>0){
                dp1_idx[r]=dp1_idx[r-1];
                dp1[r]=dp1[r-1];
            }
            if(sum>cur_max){
                cur_max=sum;
                dp1_idx[r]=l;
            }
            dp1[r]=max(dp1[r],sum);
            if(l>=k && r+k<n){
                int lf=dp1[l-1];
                int cur=sum;
                int rt=dp[r+1];
                int tot=lf+cur+rt;
                if(tot>mini){
                    mini=tot;
                    idx=dp1_idx[l-1];
                    idx1=l;
                    idx2=dp_idx[r+1];
                }
            }
         }   
        }
    return {idx,idx1,idx2};
    }
};