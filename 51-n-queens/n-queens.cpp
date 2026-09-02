class Solution {
public:
 void backtrack(int col,vector<vector<string>>&ans,vector<string>&check,vector<int>&l,vector<int>&up,vector<int>&low,int n){
         if(col==n){
            ans.push_back(check);
         }   
         for(int row=0;row<n;row++){
            if(l[row]==0 && up[n-1+col-row]==0 &&
               low[row+col]==0){
                check[row][col]='Q';
                l[row]=1;
                low[row+col]=1;
                up[n-1+col-row]=1;
               backtrack(col+1,ans,check,l,up,low,n);
               check[row][col]='.';
                l[row]=0;
                low[row+col]=0;
                up[n-1+col-row]=0;
               }
         }
          }
    vector<vector<string>>solveNQueens(int n){
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>check(n);
        for(int i=0;i<n;i++){
            check[i]=s;
        }
        vector<int>up(2*n-1);
        vector<int>l(n);
        vector<int>low(2*n-1);
        backtrack(0,ans,check,l,up,low,n);

       return ans;
    }
};