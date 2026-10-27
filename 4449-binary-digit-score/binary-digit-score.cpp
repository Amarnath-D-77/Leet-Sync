class Solution {
public:
    int calculateScore(int a,int b){
       
        int v=0,v1=0;
        while(a>0){
            
            if(a%2==1){
                v++;
            }
            a/=2;
        }
         while(b>0){
           
             if(b%2==1){
                v1++;
            }
            b/=2;
        }
        if(v>=v1){
            return v*v1;
        }
        return v1/v;
    }
};