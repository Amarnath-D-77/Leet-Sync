/*
  OBSERVATION:
                                            idx:  0   1   2    3   4 
                     suppose there are two boxes [111][2][1111][22][33]
  To remove all the boxes there are following two options

  option 1--> remove the curent box and obtain the reward
              idx 0:[111]
              idx 1...4  :[2][1111][22][33]
          remove box at idx 0 and obtain the reward and proceed to do find the best for  
           i+1--->j
  option 2-->find the box for merging with idx0 
  idx0:[111]---> idx2[1111]
  for the above to happend we must remove all boxes between idx0+1-->idx2-1 
  that is solved by rec(box,ocur,dp,i+1,k-1,0)   
   and    rec(box,ocur,dp,k,j,extra+ocur[i]) for this 
   now consider the boxes at idx0 and idx2 are merged and we pass on the combined box to future 
   and see if we can find another box with same label ie(extra+ocur[i]);
 
*/
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