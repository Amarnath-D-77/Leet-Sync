class Solution{
    int n;
    vector<int>bit;
    void add(int i,int val){
        for(;i<=n;i+=i&-i){
            bit[i]+=val;
        }
    }
    int query(int i)const{
      int sum=0;
      for(;i>0;i-=i&-i){
         sum+=bit[i];
      }
      return sum;
    }
    bool checkpeak(int i,const vector<int>&nums){
        if(i<=0 || i>=n-1){
           return false;
        }
        return nums[i]>nums[i-1] && nums[i]>nums[i+1];
    }
public:
    vector<int>countOfPeaks(vector<int>&nums,vector<vector<int>>&queries){
        n=nums.size();
        bit.assign(n+1,0);
        vector<int>ispeak(n,0);
        for(int i=1;i<n-1;i++){
            if(checkpeak(i,nums)){
                ispeak[i]=1;
                add(i+1,1);
            }
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==1){
                int l=queries[i][1],r=queries[i][2];
                if(r-l<2){
                   ans.push_back(0);
                }
                else{
                ans.push_back(query(r)-query(l+1));
                }
            }
            else{
              int idx=queries[i][1],val=queries[i][2];
              nums[idx]=val;
              for(int j=idx-1;j<=idx+1;j++){
                if(j<=0 || j>=n-1){
                    continue;
                }
                int newstate=checkpeak(j,nums)?1:0;
                if(newstate!=ispeak[j]){
                    add(j+1,newstate-ispeak[j]);
                    ispeak[j]=newstate;
                }
              }
            }
        }
        return ans;
    }
};