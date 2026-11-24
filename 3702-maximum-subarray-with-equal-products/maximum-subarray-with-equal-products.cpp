class Solution {
public:
    int maxLength(vector<int>&nums){
        int n=nums.size();
        int maxi=1;
        for(int i=0;i<n;i++){
            vector<int>v;
            long long prod=1;
            int g;
            int l;
            for(int j=i;j<n;j++){
                v.push_back(nums[j]);
                prod=1LL*prod*nums[j];
                if(prod>2520){
                    break;
                }
                if(i==j){
                 g=nums[j];
                 l=nums[j];
                }
                else{
                    g=gcd(g,nums[j]);
                    l=lcm(l,nums[j]);
                }
                if(prod==(long long)g*l){
            maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};