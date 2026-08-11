class Solution {
public:
    string minWindow(string s,string t){
        int ss=s.size();
        int ts=t.size();
     unordered_map<char,int>um;
     for(char c:t){
        um[c]++;
     }
     int req=um.size();
     int i=0,formed=0,len=-1,cur_idx=-1;
     unordered_map<char,int>um1;
     for(int j=0;j<s.size();j++){
        char c=s[j];
        um1[c]++;
        if(um.count(c) && um1[c]==um[c]){
            formed++;
        }
        while(i<=j && formed==req){
            int ch=s[i];
         if(len==-1 || j-i+1<len){
            len=j-i+1;
            cur_idx=i;
         }
         um1[ch]--;
         if(um.count(ch) && um1[ch]<um[ch]){
            formed--;
         }
         i++;
        }
     }
     return (len==-1)?"":s.substr(cur_idx,len);
    }
};