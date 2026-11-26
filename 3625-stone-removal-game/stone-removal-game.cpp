class Solution{
public:
    bool canAliceWin(int n){
        int cur=10;
        bool ch=false;
        while(n-cur>=0){
            if(cur%2==0){
                ch=true;
            }
            else{
                ch=false;
            }
            n-=cur;
            cur--;
        }
        return ch;
    }
};