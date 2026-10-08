class Solution {
public:
    string removeOuterParentheses(string s) {
    int a=0;
    string ss;
    for(char c:s){
        if(c=='('){
            if(++a>1){
         ss+=c;
            }
        }
    
     else if(c==')'){
            if(--a>0){
         ss+=c;
            }
        }

    }
return ss;
   
    }
};