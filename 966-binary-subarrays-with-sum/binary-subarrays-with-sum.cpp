class Solution {
public:
    int slide(vector<int>&v,int tar){
        if(tar<0){
         return 0;
        }
      int i=0,ans=0,cnt=0;
      for(int j=i;j<v.size();j++){
        if(v[j]==1){
            cnt++;
        }
        while(cnt>tar){
          if(v[i]==1){
            cnt--;
          }
          i++;
        }
        ans+=j-i+1;
      }
      return ans;
    }
    int numSubarraysWithSum(vector<int>& nums,int goal){
    int ans=slide(nums,goal)-slide(nums,goal-1);
    return ans;    
    }
};