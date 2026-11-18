class Solution {
public:
    int minChanges(string s){
        int cnt=0,o=0,z=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                o++;
            }
            if(s[i]=='0'){
                z++;
            }
            if(cnt%2!=0){
               ans+=min(o,z);
               o=0;
               z=0;
            }
            cnt++;
        }
        return ans;
    }
};