class Solution {
public:
    void rec(vector<int>&digits,vector<bool>&check,int n,set<int>&st,int &cnt){
        if(n>=100 && n<1000){
            if(n%2==0 && !st.contains(n)){
                st.insert(n);
                cnt+=1;
            }
           return;
        }
        for(int i=0;i<digits.size();i++){
            if(check[i]==true){
                check[i]=false;
                 rec(digits,check,(n*10)+digits[i],st,cnt);
                 check[i]=true;
            }
        }
    }
    int totalNumbers(vector<int>&digits){
        int ans=0;
        set<int>st;
        for(int i=0;i<digits.size();i++){
         if(digits[i]!=0){
         vector<bool>check(digits.size(),true);
         check[i]=false;   
         rec(digits,check,digits[i],st,ans);
         check[i]=true;
         }
        }
        return ans;
    }
};