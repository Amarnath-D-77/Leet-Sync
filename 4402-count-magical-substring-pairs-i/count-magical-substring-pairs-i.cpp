class Solution {
public:
    int countMagicalPairs(string s){
        int n=s.size(),cnt=0;
        vector<vector<int>>v(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            set<char>st;
           for(int j=i;j<n;j++){
            st.insert(s[j]);
               v[i][j]=st.size();
            }
        }
       for(int j=0;j<n-1;j++){
        int d[27]={0};
        for(int k=j+1;k<n;k++){
            d[v[j+1][k]]++;
        }
        for(int i=0;i<=j;i++){
         cnt+=d[v[i][j]];
        }
       }
       return cnt;
    }
};