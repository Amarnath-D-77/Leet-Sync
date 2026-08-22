class Solution {
public:
    bool checkDivisibility(int n){
       string s=to_string(n);
       int prod=1;
       int sum=0;
       for(char c:s){
       prod*=c-'0';
       sum+=c-'0';
       }
       
       return n%(sum + prod)==0;
    }
};