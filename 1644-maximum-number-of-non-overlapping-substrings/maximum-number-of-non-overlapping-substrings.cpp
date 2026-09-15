class Solution {
public:
    vector<string>maxNumOfSubstrings(string s){
         
         vector<int>left(26,-1);
         vector<int>right(26,-1);
         for(int i=0;i<s.size();i++){
            if(left[s[i]-'a']==-1){
                left[s[i]-'a']=i;
            }
            right[s[i]-'a']=i;
         }
         struct Interval{
            int st,end;
         };
         vector<Interval>v;
         for(int i=0;i<26;i++){
            if(left[i]==-1){
                continue;
            }
            int star=left[i];
            int endd=right[i];
            int check=true;
            for(int j=star;j<=endd;j++){
                if(left[s[j]-'a']<star){
                    check=false;
                    break;
                }
                endd=max(endd,right[s[j]-'a']);
            }
           if(check){
            v.push_back({star,endd});
           }
         }
         sort(v.begin(),v.end(),[](const Interval&a,const Interval&b){
            if(a.end!=b.end){
                 return a.end<b.end;
            }
            return a.st>b.st;
         });
         int cur=-1;
         vector<string>ans;
         for(int i=0;i<v.size();i++){
            if(cur<v[i].st){
                ans.push_back(s.substr(v[i].st,v[i].end-v[i].st+1));
                cur=v[i].end;
            }
         }
         return ans;
    }
};