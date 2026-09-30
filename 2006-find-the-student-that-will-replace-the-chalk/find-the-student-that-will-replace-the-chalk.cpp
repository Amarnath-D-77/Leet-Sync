class Solution {
public:
    int chalkReplacer(vector<int>&chalk,int k){
        int n=chalk.size();
       
        long long  tot=0;
        for(int i=0;i<n;i++){
            tot+=chalk[i];
        }
        int rem=k%tot;
        int ans=0;
        for(int i=0;i<n;i++){
            if(rem-chalk[i]<0){
                break;
            }
            rem-=chalk[i];
            ans++;
        }
     return ans;
    }
};