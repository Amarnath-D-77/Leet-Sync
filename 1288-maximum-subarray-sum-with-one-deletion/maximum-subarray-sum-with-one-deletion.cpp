/*
OBSERVATION:
       states:
            1.no deletions: standard kadane
            2.deletions: if we delete now ,then take no_delete of previous;
                         if not delete now, then take delete of previous+v[curr];
*/
class Solution {
public:
    int dp[100005][2];
    int memo(int i,int del_nodel,vector<int>&v){
        if(i==0){
            if(del_nodel==0){
                return v[i];
            }
            return -1e9;
        }
        if(dp[i][del_nodel]!=-1){
            return dp[i][del_nodel];
        }
        if(del_nodel==0){
            int keep=memo(i-1,0,v)+v[i];
            int skip=v[i];
            dp[i][del_nodel]=max(keep,skip);
            return dp[i][del_nodel];
        }
        int d_now=memo(i-1,0,v);
        int not_now=memo(i-1,1,v)+v[i];
        dp[i][del_nodel]=max(d_now,not_now);
         return dp[i][del_nodel];
    }

    int maximumSum(vector<int>&arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            maxi=max({maxi,memo(i,0,arr),memo(i,1,arr)});
        }
    return maxi;
    }
};