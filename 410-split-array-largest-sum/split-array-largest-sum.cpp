/* reducing mid gives more k so that 
   we can find the minimum mid which gives more k
*/
class Solution {
public:
      int bins(int sum,vector<int>&v,int k){
        int cur=0;
        int cnt=1;
        for(int x:v){
            if(cur+x<=sum){
              cur+=x;
            }
            else{
              cnt++;
              cur=x;
            }
        }

        return cnt<=k;
      }
    int splitArray(vector<int>&nums,int k){
        int l=*max_element(nums.begin(),nums.end()),h=0;
        for(int x:nums){
           h+=x;
        }
        h+=1;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(bins(mid,nums,k)){
               ans=mid;
              h=mid-1;
            }
            else{
             l=mid+1;
            }
        }
        return ans;
    }
};