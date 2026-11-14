class Solution {
public:
    bool checkPossibility(vector<int>&nums){
        int cnt=0;
        vector<int>v=nums;
        vector<int>v1=nums;
        vector<int>v2=nums;
        vector<int>v3=nums;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                cnt++;
            }
        }
        if(cnt>1){
            return false;
        } 
     
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                v[i]=nums[i+1];
                v3[i+1]=nums[i];
                if(i>0){
                 v1[i]=max(nums[i+1]-1,v1[i-1]);
                }
                else{
                  v1[i]=nums[i+1]-1;
                }
                if(i+1<nums.size()-1){
                    v2[i]=min(v2[i+2],v2[i]+1);
                }
                else{
                    v2[i]=v2[i]+1;
                }
                break;
            }
        }
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<endl;
        for(int x:v1){
            cout<<x<<" ";
        }
        cout<<endl;
        for(int x:v2){
            cout<<x<<" ";
        }
        cout<<endl;
        for(int x:v3){
            cout<<x<<" ";
        }
        cout<<endl;
       if(is_sorted(v.begin(),v.end()) ||
          is_sorted(v1.begin(),v1.end()) ||
          is_sorted(v2.begin(),v2.end()) ||
          is_sorted(v3.begin(),v3.end()) 
           ){
            return true;
           }
           return false;
    }
};