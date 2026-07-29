class Solution {
public:
int slide(vector<int>&nums,int k){
     int i=0,ans=0,cnt=0;
        for(int j=i;j<nums.size();j++){
            if(nums[j]%2!=0){
                cnt++;
            }
            while(cnt>k){
                if(nums[i]%2!=0){
                    cnt--;
                }
                i++;
            }
          ans+=j-i+1;
        }
       return ans;
}
    int numberOfSubarrays(vector<int>&nums,int k){
       int ans=slide(nums,k)-slide(nums,k-1);
       return ans;
    }
};