class Solution {
public:
    long long minimumCost(int cost1,int cost2,int costBoth,int need1,int need2){
        long long ans;
        if(cost1+cost2>=costBoth){
            long long  mini=min(need1,need2),maxi=max(need1,need2);
            ans=mini*costBoth;
            long long  rem=maxi-mini;
            if(maxi==need1){
               if(rem*cost1<=rem*costBoth){
                ans+=rem*cost1;
               }
               else{
                ans+=rem*costBoth;
               }
            }
             else{
               if(rem*cost2<=rem*costBoth){
                ans+=rem*cost2;
               }
               else{
                ans+=rem*costBoth;
               }
            }
            
        }
        else{
            return ((long long)cost1*(long long)need1)+((long long )cost2*(long long)need2);
        }
        return ans;
    }
};