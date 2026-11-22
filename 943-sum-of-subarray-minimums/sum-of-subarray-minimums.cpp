class Solution {
public:
    int sumSubarrayMins(vector<int>&arr){
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
        int ans=0;
        for(int i=0;i<n;i++){
            int a=i-L[i];
            int b=R[i]-i;
            ans=(ans+1LL*arr[i]*a%MOD*b%MOD)%MOD;
        }
       return ans;
    }
};