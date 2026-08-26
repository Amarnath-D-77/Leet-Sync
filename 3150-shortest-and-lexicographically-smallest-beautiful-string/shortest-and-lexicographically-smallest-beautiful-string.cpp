class Solution {
public:
    string shortestBeautifulSubstring(string s, int k){
        int l=0,cnt=0;
        string ans="";
        vector<string>v;
        int r;
        for( r=0;r<s.size();r++){
            if(s[r]=='1'){
                cnt++;
            }
            while(cnt>k){
                if(s[l]=='1'){
                    cnt--;
                }
                l++;
            }
            while(s[l]=='0' && cnt==k){
                    l++;
                }
            if(cnt==k){
            v.push_back(s.substr(l,r-l+1));
            }
          }
            while(s[l]=='0' && cnt==k){
                    l++;
                }
                if(cnt==k){
                   
            v.push_back(s.substr(l,r-l+1));
            }
            for(string s:v){
                cout<<s<<endl;
            }
       sort(v.begin(),v.end(),[&](const string &a,const string &b){
        if(a.size()==b.size()){
            return a<b;
        }
        return a.size()<b.size();
       });
       if(v.empty()){
        return "";
       }
       return v[0];
    }
};