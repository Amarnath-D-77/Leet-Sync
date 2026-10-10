class Solution {
public:
    int scoreOfParentheses(string s){
        int dep=0,sc=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='('){
                dep++;
            }
            else{
                dep--;
                if(s[i-1]=='('){
                  sc+=pow(2,dep);
                }
            }
        }
       return sc;
    }
};