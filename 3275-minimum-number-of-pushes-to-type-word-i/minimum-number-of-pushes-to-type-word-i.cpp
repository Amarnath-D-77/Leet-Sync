class Solution {
public:
    int minimumPushes(string word){
    unordered_map<char,int>m;
    for(char c:word){
    m[c]++;
    }
    vector<pair<char,int>>um;
    for(auto x:m){
        um.push_back({x.first,x.second});
    }
     sort(um.begin(),um.end(),[&](const auto&a,const auto&b){
        return a.second>b.second;
     });
    int tot=0,mul=1,cnt=0;
    for(auto x:um){
       tot+=(x.second)*mul;
       cnt++;
       if(cnt==8){
        cnt=0;
        mul++;
       }
    }
    return tot;
    }
};
        