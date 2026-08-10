class Solution {
public:
    int slide(vector<int>v,int k){
        /* if k==4 ,[LLMRR]
           if k==5 ,[LLMR]
           the above thing is for every window ,we use this 
           to caluate the swaps for every window in O(1)
     */
        int L_cnt=k/2;
        int R_cnt=k-L_cnt-1;
        int n=v.size();
        vector<int>pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+v[i];
        }
        int ans=INT_MAX;
        for(int i=0;i<=n-k;i++){
            int median=i+k/2;
            // [L...M-1]
            int left_sum=pref[(median-1)+1]-pref[i];
            // [M+1...R]
            int right_sum=pref[(i+k-1)+1]-pref[median+1];
            // left_swaps=(v[median]*L_cnt)-left_sum for every window
            //right_swaps=(v[median]*R_cnt)-right_sum for every window
            int  left_swaps=(v[median]*L_cnt)-left_sum;
            int  right_swaps=abs((v[median]*R_cnt)-right_sum); 
            ans=min(ans,left_swaps+right_swaps);
        }
        return ans;
    }
    int help(vector<int>&nums,int k){
       vector<int>v;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
        v.push_back(i-v.size());
        }
       }
       int ans=slide(v,k);
       return ans;
    }
    int minMoves(vector<int>&nums,int k){
       int ans=help(nums,k);
        return ans;
    }
};