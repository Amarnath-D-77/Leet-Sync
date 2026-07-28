class Solution {
public:
long long bins(vector<int>&v,long long tar){
    long long cur=0,k_s=1;
    for(int i=0;i<v.size();i++){
      if(cur+v[i]<=tar){
        cur+=v[i];
      }
      else{
      k_s++;
      cur=v[i];
      }
    }
    return k_s;
}
    int splitArray(vector<int>&nums,int k){
        long long left=*max_element(nums.begin(),nums.end());
        long long right=0;
        int ans;
        for(int x:nums){
            right+=(long long)x;
        }
        while(left<=right){
            long long mid=(left+right)/2;
            long long cnt=bins(nums,mid);
           if(cnt<=k){
            ans=(int)mid;
            right=mid-1;
           }
           else{
            left=mid+1;
           }
        }
        return ans;
    }
};