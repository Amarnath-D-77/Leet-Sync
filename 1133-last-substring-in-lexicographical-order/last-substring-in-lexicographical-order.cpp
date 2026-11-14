class Solution {
public:
    char alpha = 'a';
    string lastSubstring(string s) {
        int n = s.length();
        for(char c : s){
            alpha = max(alpha , c);
        }
        vector<int> ind;
        for(int i=0;i<n;i++){
            if(s[i] == alpha) ind.push_back(i); 
        }

        int best = ind.back();
        int idx = ind.size() - 2;
        while(idx >= 0){
            int cont = ind[idx];         
            int diff = best - cont;
            int k = 0;
            for(;k<diff && best+k<n ; k++){
                if(s[cont+k] != s[best+k]) break;
            }
            
            if(k == diff || best+k == n || s[cont+k] > s[best+k]) best = cont;            

            idx--;
        }
        return s.substr(best , n-best);
    }
};