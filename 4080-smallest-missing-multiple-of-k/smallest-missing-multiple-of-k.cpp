class Solution {
public:
    int missingMultiple(vector<int>&nums,int k){
        int kk=k;
        while(find(nums.begin(),nums.end(),k)!=nums.end()){
           k+=kk;
        }
        return k;
    }
};