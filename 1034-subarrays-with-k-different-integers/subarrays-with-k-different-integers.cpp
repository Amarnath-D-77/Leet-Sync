class Solution {
public:
    int slide(vector<int>&nums,int tar){
        int n=nums.size();
         unordered_map<int,int>um;
        int i=0,cnt=0;
        for(int j=0;j<n;j++){
            um[nums[j]]++;
            while(um.size()>tar){
             um[nums[i]]--;
             if(um[nums[i]]==0){
                    um.erase(nums[i]);
                }
             i++;
            }
            cnt+=j-i+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>&nums,int k){
     int ans=slide(nums,k)-slide(nums,k-1);
     return ans;    
    }
};