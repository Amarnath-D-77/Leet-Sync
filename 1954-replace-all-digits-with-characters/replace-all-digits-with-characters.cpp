class Solution {
public:
    string replaceDigits(string s){
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(i%2==0){
            int cur=s[i]-'a'+1;
            cout<<cur+s[i+1]-'0';
            char c=char(96+cur+(s[i+1]-'0'));
            s[i+1]=c;
            }
        }
        return s;
    }
};