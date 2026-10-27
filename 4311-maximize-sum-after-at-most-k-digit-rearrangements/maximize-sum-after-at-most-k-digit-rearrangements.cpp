class Solution {
public:
    long long maximizeSum(vector<int>&nums,int k){
        int n=nums.size();
        vector<pair<int,int>>rev;
        for(int i=0;i<n;i++){
           string s=to_string(nums[i]);
           sort(s.rbegin(),s.rend());
           rev.push_back({stoi(s),nums[i]});
        }
        sort(rev.rbegin(),rev.rend(),[](auto &a,auto &b){
            return a.first-a.second<b.first-b.second;
        });
        long long sum=0;
        for(auto x:rev){
            int ke=x.first,va=x.second;
            if(va<ke && k>0){
                sum+=ke;
                k--;
            }
            else{
                sum+=va;
            }
        }
      
        return sum;
    }
};