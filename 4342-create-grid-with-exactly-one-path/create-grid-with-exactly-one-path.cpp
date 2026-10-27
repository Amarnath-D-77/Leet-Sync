class Solution {
public:
    vector<string> createGrid(int m, int n){
        vector<vector<char>>v(m,vector<char>(n,'.'));
        vector<string>v1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0 || i==m-1){
                    continue;
                }
                else{
                    v[i][j]='#';
                }
            }
        }
       for(int i=0;i<m;i++){
           string s="";
            for(int j=0;j<n;j++){
               s+=v[i][j];
            }
          v1.push_back(s);
        }
        return v1;
    }
};