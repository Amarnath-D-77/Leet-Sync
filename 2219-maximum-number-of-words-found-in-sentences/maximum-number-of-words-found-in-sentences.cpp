class Solution {
public:
    int mostWordsFound(vector<string>&sentences){
        int mini=-1;
        for(string s:sentences){
            int cnt=0;
            for(char c:s){
                if(c==' '){
                 cnt++;
                }
            }
             mini=max(mini,cnt+1);
        }
        return mini;
    }
};