class Solution {
public:
    int rec(vector<int>&box,vector<int>&ocur,vector<vector<vector<int>>>&dp,int i,int j,int extra){
     if(i>j){
        return 0;
     }
     if(dp[i][j][extra]!=-1){
        return dp[i][j][extra];
     }
     int ans=(ocur[i]+extra)*(ocur[i]+extra)+rec(box,ocur,dp,i+1,j,0);
     for(int k=i+2;k<=j;k++){
       if(box[i]==box[k]){
        ans=max(ans,rec(box,ocur,dp,i+1,k-1,0)+rec(box,ocur,dp,k,j,extra+ocur[i]));
       }
     }
     return dp[i][j][extra]=ans;
    }
    int removeBoxes(vector<int>&boxes){
        int n=boxes.size();
        vector<int>ocur;
        vector<int>box;
        int cnt=1;
        for(int i=0;i<n-1;i++){
         if(boxes[i]==boxes[i+1]){
            cnt++;
         }
         else{
            ocur.push_back(cnt);
            box.push_back(boxes[i]);
            cnt=1;
         }
        }
        ocur.push_back(cnt);
        box.push_back(boxes[n-1]);
        vector<vector<vector<int>>>dp(102,vector<vector<int>>(102,vector<int>(102,-1)));
        int ans=rec(box,ocur,dp,0,box.size()-1,0);
        return ans;
    }
};