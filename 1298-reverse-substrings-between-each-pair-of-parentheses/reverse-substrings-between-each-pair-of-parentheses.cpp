class Solution {
public:
    string reverseParentheses(string s){
        string s1="";
        stack<int>st;
        for(char c:s){
            if(c=='('){
            st.push(s1.size());
            }
            else if(c==')'){
                int stt=st.top();
                st.pop();
                reverse(s1.begin()+stt,s1.end());
            }
            else{
                s1+=c;
            }
        }
        return s1;
    }
};