class Solution {
public:
    void bactrack(int col,int &ans,vector<int>&l,vector<int>&up,
                   vector<int>&low,int n){
                    if(col==n){
                      ans++;
                    }
                    for(int row=0;row<n;row++){
                        if(l[row]==0 && up[n-1+col-row]==0 &&
                           low[row+col]==0){
                            l[row]=1;
                            up[n-1+col-row]=1;
                            low[row+col]=1;
                            bactrack(col+1,ans,l,up,low,n);
                            l[row]=0;
                            up[n-1+col-row]=0;
                            low[row+col]=0;
                           }
                    }

                   }
                   
    int totalNQueens(int n){
        int ans=0;
        vector<int>l(n);
        vector<int>up(2*n-1);
        vector<int>low(2*n-1);
        bactrack(0,ans,l,up,low,n);
    return ans;
    }
};