class Solution {
public:
      int largemonostack(vector<int>&arr,vector<long long>&pre){
        int MOD=1e9+7;
        int n=arr.size();
        stack<int>st;
        vector<int>L(n,-1);
        vector<int>R(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                L[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                R[i]=st.top();
            }
            st.push(i);
        }
        long long ans=LLONG_MIN;
        for(int i=0;i<n;i++){
            long long cur=(pre[R[i]]-pre[L[i]+1])*arr[i];
            ans=max(ans,cur);
        }
        return ans%MOD;
    }
    int maxSumMinProduct(vector<int>&nums){
        int n=nums.size();
        int MOD=1e9+7;
        vector<long long>pre(n+1);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        return largemonostack(nums,pre);
    }
};