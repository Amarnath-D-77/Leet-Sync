class Solution {
public:
    int minAddToMakeValid(string s){
        int sc=0,ans=0;
        for(char c:s){
            if(c=='('){
                sc++;
            }
            else{
                sc--;
            }
            if(sc<0){
                sc++;
                ans++;
            }
        }
        if(sc>0){
            ans+=sc;
        }
      return ans;
    }
};