class Solution {
public:
    int numEnclaves(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==1){
                  q.push({i,j});
                  grid[i][j]=0;
                }
            }
        }
        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto cur=q.front();
            int r=cur.first;
            int c=cur.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(nr>=0 && nc<m && nc>=0 && nr<n){
                    if(grid[nr][nc]==1){
                        q.push({nr,nc});
                        grid[nr][nc]=0;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
return ans;
        
    }
};