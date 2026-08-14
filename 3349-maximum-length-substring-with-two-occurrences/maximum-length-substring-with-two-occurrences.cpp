class Solution {
public:
    int maximumLengthSubstring(string s){
        int n=s.size();
      unordered_map<char,int>um;
      set<char>st;
      for(char c:s){
        st.insert(c);
      }
      int i=0,cnt=0;
      for(int j=0;j<n;j++){
        um[s[j]]++;
        while(i<=j && um[s[j]]>2){
            um[s[i]]--;
            if(um[s[i]]==0){
                um.erase(s[i]);
            }
            i++;
        }
    
            cnt=max(cnt,j-i+1);
        
    }
  
    return cnt;
    }
};