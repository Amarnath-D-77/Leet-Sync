class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>&nums,int firstLen,int secondLen){
        int n=nums.size();
        vector<int>dp1(n,INT_MIN);
        vector<int>dp2(n,INT_MIN);
        int cur=0;
        int l=0;
        for(int r=0;r<n;r++){
             cur+=nums[r];
             if(r-l+1>firstLen){
                cur-=nums[l];
                l++;
             }
             if(r+1>=firstLen && r>0){
             dp1[r]=max(dp1[r-1],cur);
             }
             else if(firstLen==1){
                dp1[r]=cur;
             }
            
        }
        l=n-1;
        cur=0;
        for(int r=n-1;r>=0;r--){
            cur+=nums[r];
            if(l-r+1>secondLen){
                cur-=nums[l];
                l--;
            }
            if(n-r>=secondLen && r<n-1){
                dp2[r]=max(dp2[r+1],cur);
            }
            else if(secondLen==1){
                dp2[r]=cur;
            }
        }
       vector<int>dp3(n,INT_MIN);
       vector<int>dp4(n,INT_MIN);
        l=n-1;
        cur=0;
        for(int r=n-1;r>=0;r--){
            cur+=nums[r];
            if(l-r+1>firstLen){
                cur-=nums[l];
                l--;
            }
            if(n-r>=firstLen && r<n-1){
                dp3[r]=max(dp3[r+1],cur);
            }
            else if(firstLen==1){
                dp3[r]=cur;
            }
        }
        l=0;
        cur=0;
         for(int r=0;r<n;r++){
             cur+=nums[r];
             if(r-l+1>secondLen){
                cur-=nums[l];
                l++;
             }
             if(r+1>=secondLen && r>0){
             dp4[r]=max(dp4[r-1],cur);
             }
             else if(secondLen==1){
                dp4[r]=cur;
             }
        }
        int maxi1=-1;
        int maxi2=-1;
        for(int i=0;i<n-1;i++){
            if(dp1[i]!=INT_MIN && dp2[i+1]!=INT_MIN){
                maxi1=max(maxi1,dp1[i]+dp2[i+1]);
            }
        }
         for(int i=0;i<n-1;i++){
            if(dp3[i+1]!=INT_MIN && dp4[i]!=INT_MIN){
                maxi1=max(maxi1,dp3[i+1]+dp4[i]);
            }
        }
        return max(maxi1,maxi2);
    }
};