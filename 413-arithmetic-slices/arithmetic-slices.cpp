class Solution {
public:
    int numberOfArithmeticSlices(vector<int>&nums){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cur=0,cur1=-1;
             if(i+1<nums.size()){
               cur=nums[i+1]-nums[i];
             }
            for(int j=i+1;j<nums.size();j++){
                cur1=nums[j]-nums[j-1];
                if(cur1==cur && j-i+1>=3){
                    ans++;
                }
                else if(cur1!=cur){
                    break;
                }
            }
        }
     return ans;
    }
};