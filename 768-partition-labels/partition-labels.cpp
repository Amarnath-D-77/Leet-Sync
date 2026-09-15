class Solution {
public:
    vector<int> partitionLabels(string s){
        unordered_map<char,int>um;
        unordered_map<char,int>curm;
        for(char c:s){
            um[c]++;
        }
        int i=0;
        int cnt=0;
        set<char>st;
        vector<int>ans;
        for(int j=0;j<s.size();j++){
            st.insert(s[j]);
            curm[s[j]]++;
            if(um[s[j]]==curm[s[j]]){
                cnt++;
            }
            if(cnt==st.size()){
              ans.push_back(j-i+1);
              st.clear();
              cnt=0;
              i=j+1;
            }
        }
        return ans;
    }
};