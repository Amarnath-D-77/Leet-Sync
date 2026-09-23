class Solution {
public:
    string removeOccurrences(string s, string part){
        string res="";
        int len=part.size();
        for(char c:s){
           res.push_back(c);
           if(res.size()>=len && res.substr(res.size()-len)==part){
            res.erase(res.size()-len);
           }
        }
    return res;  
    }
};