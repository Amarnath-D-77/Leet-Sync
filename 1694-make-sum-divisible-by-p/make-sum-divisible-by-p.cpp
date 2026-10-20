class Solution {
public:
    int minSubarray(vector<int>&nums,int p){
        map<int,int>um;
        um[0]=-1;
        long long tot=0;
        for(int x:nums){
            tot+=x;
        }
       int tar=tot%p;
        if(tar==0){
            return 0;
        }
        int cur=0,rem,len=INT_MAX;
        for(int i=0;i<nums.size();i++){
            cur=(cur+nums[i])%p;
            int need=(cur-tar+p)%p;
            if(um.find(need)!=um.end()){
               len=min(len,i-um[need]);
            }
            um[cur]=i;
        }
        if(len==INT_MAX || len==nums.size()){
            return -1;
        }
        return len;
    }
};