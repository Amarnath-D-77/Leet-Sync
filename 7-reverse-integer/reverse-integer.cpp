class Solution {
public:
    int reverse(int x) {
        //x=3,num=3,x=12;
        //x=2,num=32;x=1
        //x=1,num=321;x=0
        long num=0;
        while(x!=0){
            int num1=x%10;
            num=(num*10)+num1;
            x=x/10;
      
        }
        if(num<INT_MIN || num>INT_MAX){
            return 0;
        }else{
        return num;}
    }
};