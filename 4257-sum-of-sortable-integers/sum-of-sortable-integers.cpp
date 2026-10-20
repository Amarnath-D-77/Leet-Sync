class Solution {
public:
    int sortableIntegers(vector<int>&nums){
          int n=nums.size(),tot=0;
          vector<int>v(nums.begin(),nums.end());
          sort(v.begin(),v.end());
          vector<int>v1;
          for(int k=1;k<=n;k++){
           if((n%k)!=0){
              continue;
           }
               bool ch=true;
               v1.resize(k);
               for(int i=0;i<n;i+=k){
                  
                  for(int j=0;j<k;j++){
                    v1[j]=nums[i+j];
                  }
                  sort(v1.begin(),v1.end());
                  for(int j=0;j<k;j++){
                    if(v1[j]!=v[i+j]){
                        ch=false;
                        break;
                    }
                  }
                  if(!ch){
                    break;
                  }

               int de=0;

               for(int j=0;j<k;j++){
                if(nums[i+j]>nums[i+(j+1)%k]){
                    de++;
                }
               }
              if(de>1){
                ch=false;
                break;
              }
             
               }
           if(ch){
            tot+=k;
            }
          }
          return tot;
    }
};