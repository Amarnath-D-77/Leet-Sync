class Solution {
public:
    vector<int>resultArray(vector<int>&nums){
        vector<int>v;
        vector<int>v1;
        v.push_back(nums[0]);
        v1.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(v.back()>v1.back()){
                v.push_back(nums[i]);
            }
            else{
                v1.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int x:v){
           ans.push_back(x);
        }
        for(int x:v1){
           ans.push_back(x);
        }
        return ans;
    }
};