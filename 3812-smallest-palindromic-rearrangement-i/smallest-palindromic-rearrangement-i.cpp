class Solution {
public:
    string smallestPalindrome(string s){
        map<char,int>m;
        for(char c:s){
            m[c]++;
        }
        vector<pair<char,int>>v;
        string c="";
        for(auto x:m){
            int si=x.second/2;
            if(x.second%2!=0 || si==0){
              c=x.first;
            }
            if(si!=0){
                v.push_back({x.first,si});
            }
        }
        string st="";
        for(auto x:v){
            st.append(x.second,x.first);
        }
           string stt=st;
            reverse(stt.begin(),stt.end());
        if(c!=""){
            st+=c;
            st+=stt;
            return st;
        }
        st+=stt;
      return st;
    }
};