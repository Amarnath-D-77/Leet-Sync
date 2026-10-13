class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue){
        int cnt=0;
        for(auto &s:items){
                string tp=s[0];
                string clr=s[1];
                string na=s[2];
                 if(ruleKey=="type" && ruleValue==tp||
              ruleKey=="color" && ruleValue==clr||
               ruleKey=="name" && ruleValue==na){
                cnt++;
               }
            }
           
        
        return cnt;
    }
};