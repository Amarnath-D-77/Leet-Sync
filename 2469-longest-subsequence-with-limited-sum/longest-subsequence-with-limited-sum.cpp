class Solution {
public:
    vector<int>answerQueries(vector<int>& nums, vector<int>& queries){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>p(n);
        p[0]=nums[0];
        for(int i=1;i<n;i++){
            p[i]=p[i-1]+nums[i];
        }
        vector<int>ans;
        for(int x:queries){
            auto it=upper_bound(p.begin(),p.end(),x);
           ans.push_back(n-distance(it,p.end()));
        }
        return ans;
    }
};