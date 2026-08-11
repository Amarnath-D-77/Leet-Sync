class Solution {
public:
    int missingInteger(vector<int>&nums){
        int sum=0;
        int n=nums.size();
       
        for(int l=0;l<n-1;l++){
            if(nums[l]+1==nums[l+1]){
                if(l==0){
              sum+=nums[l]+nums[l+1];
                }
                else{
                    sum+=nums[l+1];
                }
            }
            else{
                break;
            }
        }     
        set<int>s;
        for(int x:nums){
            s.insert(x);
        }
         if(sum==0){
            sum=nums[0];
        }
          while(s.contains(sum)){
             sum++;
          }
          return sum;
    }
};