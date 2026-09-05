/*
OBSERVATION:
           KEY:
              no matter in which way smash the stone the answer will always be
              |S1-S2| where S1 is the sum of piles of stones of one group and 
              and S2 is another sum of stones
              
            we are considering  subset1 and subset 2 as tot/2
            we try to make pickig of items as close to subset1 sum 
            so that the  difference between the last two stones is 
            minimized 
*/
class Solution{
public:
    int lastStoneWeightII(vector<int>&stones){
        int n=stones.size();
        int tot=0;
        for(int x:stones){
            tot+=x;
        }
        int cap=tot/2;
        vector<vector<int>>dp(n+1,vector<int>(cap+1,0));  

        for(int i=1;i<=n;i++){
            for(int j=0;j<=cap;j++){
                int not_take=dp[i-1][j];
                int take=0;
                if(j-stones[i-1]>=0){
                    take=stones[i-1]+dp[i-1][j-stones[i-1]];
                }
                dp[i][j]=max(take,not_take);
            }
        }
        int pile2=tot-dp[n][cap];
       return pile2-dp[n][cap];
    }
};