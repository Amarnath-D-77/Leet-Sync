class Solution {
public:
    int minOperations(vector<int>&nums,int target){
        vector<int>v(31);
        long long ans=0,tot=0;
        for(int x:nums){
            int bit=0;
            tot+=x;
            while(!((x>>bit)&1)){
                bit++;
            }
            v[bit]++;
        }
        if(tot<target){
            return -1;
        }
       for(int i=0;i<30;i++){
           if((target>>i)&1){
            if(v[i]>0){
                v[i]--;
            }
            else{
              int j=i;
              while(j<30 && v[j]==0){
                j++;
              }
              v[j]--;
              ans+=j-i;
                for(int k=j-1;k>i;k--){
                    v[k]++;
                }
            }

           }
           v[i+1]+=v[i]/2;
       }
        return (int)ans;
    }
};