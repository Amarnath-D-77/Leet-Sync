class Solution {
public:
    int smallestNumber(int n,int t){
        int prod=1;
        string s=to_string(n);
        for(char c:s){
            prod*=c-'0';
        }
        while(prod%t!=0){
            n++;
            prod=1;
        string s=to_string(n);
        for(char c:s){
            prod*=c-'0';
        }
        }
        return n;
    }
};