class Solution {
public:
    long long countCommas(long long n){
        if(n<1000){
          return 0;
        }
         long long cur=999000;
         long long thou=1000;
         long long ans=0;
         long long cnt=1;
         while(thou*1000<=n){
            ans+=(cur*cnt)+1;
            cur*=1000;
            thou*=1000;
            cnt++;
         }
         ans+=1+((n-thou)*cnt);
        return ans;
    }
};