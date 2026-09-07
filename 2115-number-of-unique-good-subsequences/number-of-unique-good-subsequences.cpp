/*
   dp0->counts how many subseq starting with 1 ends with 0
   dp1->counts how many subseq starting with 1 ends with 1     
*/
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary){
        int MOD=1e9+7;
        int dp0=0;
        int dp1=0;
        int has_zero=0;
        for(char c:binary){
            if(c=='0'){
                has_zero=1;
                dp0=(dp0+dp1)%MOD;
            }
            else{
                dp1=(dp0+dp1+1)%MOD;
            }
        }
        return (dp0+dp1+has_zero)%MOD;
    }
};