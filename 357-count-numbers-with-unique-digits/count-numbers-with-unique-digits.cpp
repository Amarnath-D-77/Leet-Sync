class Solution {
public:
    int countNumbersWithUniqueDigits(int n){
        if(n==0)return 1;
       
       int cur=9;
       int mul=9;
       int ans=10;
      for(int i=2;i<=n;i++){
       
        cur*=mul;
        
        ans+=cur;

        mul--;
       }
       return ans;
     
    }
};