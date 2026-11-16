class Solution {
public:
    string digitSum(string s,int k){
        while(s.size()>k){
            vector<string>v;
            int cnt=0;
            string cur="";
            for(int i=0;i<s.size();i++){
                cur+=s[i];
                cnt++;
                if(cnt==k){
                 cnt=0;
                 v.push_back(cur);
                 cur="";
                }
            }
            if(cur!=""){
                v.push_back(cur);
            }
            s="";
            for(string s1:v){
                int sum=0;
              for(char c:s1){
                 sum+=c-'0';
              }
              s+=to_string(sum);
            }
        }
        return s;
    }
};