struct Rollinghash{
    static constexpr long long MOD1=1000000007;
    static constexpr long long MOD2=1000000009;
    static constexpr long long BASE1=100003;
    static constexpr long long BASE2=100019;
    vector<long long>h1,h2,p1,p2;
    Rollinghash(const vector<int>&v){
        int n=v.size();
        h1.assign(n+1,0);
        h2.assign(n+1,0);
        p1.assign(n+1,1);
        p2.assign(n+1,1);
        for(int i=0;i<n;i++){
            int val=v[i]+1;
            h1[i+1]=(h1[i]*BASE1+val)%MOD1;
            h2[i+1]=(h2[i]*BASE2+val)%MOD2;
            p1[i+1]=(p1[i]*BASE1)%MOD1;
            p2[i+1]=(p2[i]*BASE2)%MOD2;
        }
    }
     uint64_t get(int l,int r)const{
        int len=r-l+1;
        long long v1=(h1[r+1]-h1[l]*p1[len]%MOD1+MOD1)%MOD1;
        long long v2=(h2[r+1]-h2[l]*p2[len]%MOD2+MOD2)%MOD2;
        return ((uint64_t)v1<<32)|(uint64_t)v2;
     }
};
class Solution {
public:
    int smallestUniqueSubarray(vector<int>&nums){
        int n=nums.size();
        Rollinghash rh(nums);
       auto check=[&](int len)->bool{
             int m=n-len+1;
             vector<uint64_t>hashes(m);
             for(int i=0;i<m;i++){
                hashes[i]=rh.get(i,i+len-1);
             }
             sort(hashes.begin(),hashes.end());
             for(int i=0;i<m;i++){
                bool sameprev=(i>0 && hashes[i]==hashes[i-1]);
                bool samenext=(i<m-1 && hashes[i]==hashes[i+1]);
                if(!sameprev && !samenext)return true;
             }
               return false;
       };
        int low=1,high=n,ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};