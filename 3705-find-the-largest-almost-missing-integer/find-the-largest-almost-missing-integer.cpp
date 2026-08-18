class Solution {
public:
    int largestInteger(vector<int>&nums,int k){
        unordered_map<int,int>um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]=0;
        }
        
        for(int i=0;i<nums.size()-k+1;i++){
            unordered_map<int,int>um1;
            for(int j=i;j<i+k && j<nums.size();j++){   
                if(um1[nums[j]]==0){      
                um[nums[j]]+=1;
                }
                um1[nums[j]]++;  
                cout<<i<<" "<<j<<endl;  
            }
        }
        int maxi=INT_MIN;
        for(auto it:um){
          if(it.second==1){
            maxi=max(maxi,it.first);
          }
          cout<<it.first<<" "<<it.second<<endl;
        }     
        if(maxi==INT_MIN){
            return -1;
        }
       return maxi; 
    }
};