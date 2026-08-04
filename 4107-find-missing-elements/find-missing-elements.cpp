class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        vector<int>v;
    int b=*s.begin(),e=*s.rbegin();
        while(b<=e){
            if(!s.count(b)){
                v.push_back(b);
            }
            b++;
        }
        return v;
    }
};