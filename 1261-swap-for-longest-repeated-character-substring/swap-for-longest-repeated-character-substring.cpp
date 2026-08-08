class Solution {
public:
    int maxRepOpt1(string text){
        vector<char>b;
        vector<int>cnt;
        for(char c:text){
          if(b.empty() || b.back()!=c){
            b.push_back(c);
            cnt.push_back(1);
          }
          else{
            cnt.back()++;
          }
        }
        unordered_map<char,int>um;
        for(int i=0;i<b.size();i++){
          um[b[i]]+=cnt[i];
        }
        int maxi=0;
        for(int i=0;i<b.size();i++){
            maxi=max(maxi,cnt[i]+(um[b[i]]>cnt[i]?1:0));
        }
        for(int i=1;i<b.size()-1;i++){
            if(b[i-1]==b[i+1]){
              int check=um[b[i-1]]-cnt[i-1]-cnt[i+1];
                if(cnt[i]==1 && check>0){
                 maxi=max(maxi,cnt[i-1]+cnt[i+1]+1);
                }
               else if(cnt[i]==1){
             maxi=max(maxi,cnt[i-1]+cnt[i+1]);
               }
            }
        } 
        return maxi;
    }
};