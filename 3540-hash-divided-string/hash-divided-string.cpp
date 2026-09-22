class Solution {
public:
    string stringHash(string s,int k){
        int cnt=0,val=0;
        string cur="";
        string ans="";
        for(int i=0;i<s.size();i++){
            cnt+=1;
            val+=s[i]-'a';
            if(cnt%k==0){
             int asci=97+(val%26);
             char c=static_cast<char>(asci);
             ans+=c;
             cur="";
             val=0;
            }
        }
      
       return ans;
    }
};