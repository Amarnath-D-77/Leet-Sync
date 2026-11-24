/*
      pref[i]__________lo_________hg
        ^               (hg - lo )
(fixed point)
        lo-the point upto which the pref[j]-pref[i] is less than lo 
        hg - the point  which the breaks the upper bound 
    CONCLUSION: 
              for a fixed pref[i] the points lo to hg-1 inclusive are the ones whose ranges
              sum is [lower,upper]
     to calc this in o(n log n) we use modified merge sort          
*/
class Solution {
public:
long long cntrange(vector<long long>&pref,int left,int mid,int right,int lower,int upper){
       int lo=mid+1;
       int hg=mid+1;
       long long cnt=0;
       for(int i=left;i<=mid;i++){
        while(lo<=right && pref[lo]-pref[i]<lower){
            lo++;
        }
         while(hg<=right && pref[hg]-pref[i]<=upper){
            hg++;
        }
        cnt+=hg-lo;
       }
       return cnt;
    }
    void merge(vector<long long>&pref,int left,int mid,int right,int lower,int upper){
        int i=left;
        int j=mid+1;
        vector<long long>temp;
        while(i<=mid && j<=right){
            if(pref[i]>=pref[j]){
              temp.push_back(pref[j]);
              j++;
            }
            else{
              temp.push_back(pref[i]);
              i++;
            }
        }
        while(i<=mid){
            temp.push_back(pref[i]);
              i++;
        }
        while(j<=right){
            temp.push_back(pref[j]);
              j++;
        }
        for(int k=0;k<temp.size();k++){
            pref[left+k]=temp[k];
        }
    }
    long long mergeSort(vector<long long>&pref,int left,int right,int lower,int upper){
        if(left>=right){
            return 0;
        }
        int mid=left+(right-left)/2;
        long long cnt=0;
        cnt+=mergeSort(pref,left,mid,lower,upper);
        cnt+=mergeSort(pref,mid+1,right,lower,upper);
        cnt+=cntrange(pref,left,mid,right,lower,upper);
        merge(pref,left,mid,right,lower,upper);
        return cnt;
    }
    int countRangeSum(vector<int>&nums,int lower,int upper){
        int n=nums.size();
        vector<long long>pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+nums[i-1];
        }
        long long ans=mergeSort(pref,0,n,lower,upper);
        return (int)ans;
    }
};