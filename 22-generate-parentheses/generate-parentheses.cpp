class Solution { 
public: 
    void backtrack(vector<string>&ans,string &cur,int o, int c,int mp){
        if(cur.size()==2*mp){
            ans.push_back(cur);
            return;
        }
        if(o<mp){
            cur.push_back('(');
            backtrack(ans,cur,o+1,c,mp);
            cur.pop_back();
        }
        if(c<o){
            cur.push_back(')');
            backtrack(ans,cur,o,c+1,mp);
            cur.pop_back();
        }
    }
    vector<string>generateParenthesis(int n){ 
        vector<string>ans;
        string cur="";
        backtrack(ans,cur,0,0,n);
        return ans;
    } 
};