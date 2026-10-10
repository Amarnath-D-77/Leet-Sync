class Solution{
public:
      bool isvalid(string s){
           int cnt=0;
           for(char c:s){
            if(c=='('){
                cnt++;
            }
            else if(c==')'){
                cnt--;
            }
            if(cnt<0){
                return false;
            }
           }
           return cnt==0;
      }
    void dfs(string st,int start,int left,int right,vector<string>&res){
        if(left==0 && right==0){
            if(isvalid(st)){
                res.push_back(st);
            }
             return;
        }
        for(int i=start;i<st.size();i++){
            if(i>start && st[i]==st[i-1]){
                continue;
            }
            if(left>0 && st[i]=='('){
                dfs(st.substr(0,i)+st.substr(i+1),i,left-1,right,res);
            }
            if(right>0 && st[i]==')'){
                dfs(st.substr(0,i)+st.substr(i+1),i,left,right-1,res);
            }
        }
    }
    vector<string>removeInvalidParentheses(string s){
          int left=0,right=0;
          for(char c:s){
            if(c=='('){
                left++;
            }
            else if(c==')'){
                if(left>0)left--;
                else right++;
            }
          }
          vector<string>res;
          dfs(s,0,left,right,res);
          return res;
    }
};