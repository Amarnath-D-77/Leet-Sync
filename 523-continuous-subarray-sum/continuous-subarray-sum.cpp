class Solution {
public:
    bool checkSubarraySum(vector<int>&nums,int k){
        map<int,int>m;
        m[0]=-1;
        int tott=0;
      
        for(int i=0;i<nums.size();i++){
            tott+=nums[i];
           int tot=tott%k;
            if(m.count(tot)){
                int l=m[tot];
                if(i-l>1){
                    return true;
                }
            }
            else{
            m[tot]=i;
            }
        }
      return false;
    }
};