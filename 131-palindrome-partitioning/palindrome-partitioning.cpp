class Solution {
public:
bool ispalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){
        return false;
        }
        i++;
        j--;
    }
    return true;
} 
void rec(int idx,string s,vector<vector<string>>&ans,vector<string>&v){
    if(idx==s.size()){
        ans.push_back(v);
        return;
    }
    for(int i=idx;i<s.size();i++){
        string cur=s.substr(idx,i-idx+1);
        if(ispalindrome(cur)){
            v.push_back(cur);
            rec(i+1,s,ans,v);
            v.pop_back();
        }
    }
}
    vector<vector<string>>partition(string s){
     
        vector<vector<string>>ans;
        vector<string>v;
        rec(0,s,ans,v);
        return ans;
    }
};