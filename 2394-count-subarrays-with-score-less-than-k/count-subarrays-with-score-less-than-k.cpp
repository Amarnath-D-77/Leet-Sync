class Solution {
public:
long long slide(vector<int>&v,long long tar){
  long long i=0,ans=0,cnt=0;
  for(long long j=i;j<v.size();j++){
    cnt+=v[j];
    while(cnt*(j-i+1)>tar){
        cnt-=v[i];
        i++;
    }
    ans+=j-i+1; 
  }
  return ans;
}
    long long countSubarrays(vector<int>& nums, long long k){
     return slide(nums,k-1);
    }
};