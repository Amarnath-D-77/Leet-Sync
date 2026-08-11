class Solution {
public:
    long long validSubstringCount(string word1,string word2){
        long long  w1=word1.size();
        long long w2=word2.size();
        unordered_map<char,int>um;
        for(char c:word2){
            um[c]++;
        }
        long long  i=0,formed=0,req=um.size(),cnt=0;
        unordered_map<char,int>um1;
        for(int j=0;j<w1;j++){
            char c=word1[j];
            um1[c]++;
            if(um.count(c) && um[c]==um1[c]){
                formed++;
            }
            while(i<=j && formed==req){
                char ch=word1[i];
                um1[ch]--;
             if(um.count(ch) && um[ch]>um1[ch]){
                formed--;
             }
             i++;
            }
            cnt+=j-i+1;
        }
        long long  tot=w1*(w1+1)/2;
        return tot-cnt;
    }
};