class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            bool check=false;
            char ch=strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=ch){
                    check=true;
                    break;
                }
            }
            if(check){
                break;
            }
            else{
                ans+=ch;
            }
        }
      return ans;
    }
};