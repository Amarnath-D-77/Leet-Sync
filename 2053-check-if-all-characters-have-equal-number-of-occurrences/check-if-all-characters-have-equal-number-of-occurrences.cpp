class Solution {
public:
    bool areOccurrencesEqual(string s){
        unordered_map<char,int>um;
        for(char c:s){
            um[c]++;
        }
        bool check=false;
        int cur=0;
        for(auto x:um){
            if(cur==0 && !check){
                check=true;
                cur=x.second;
            }
            if(check && cur!=x.second){
                 return false;
            }
        }
        return true;
    }
};