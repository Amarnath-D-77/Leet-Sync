
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>&nums,int limit){
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<int>ans(n);
      int i=0,j;
      while(i<n){
        j=i+1;
        vector<int>ind;
        /*extending as long as the condition holds which the elements which we swap 
         in this particular window j-i+1 we can swap any number with any of the number
         within the family
        */ 
        while(j<n && v[j].first-v[j-1].first<=limit){
            j++;
        }
        for(int idx=i;idx<j;idx++){
            ind.push_back(v[idx].second);
        }
        sort(ind.begin(),ind.end());
        /*
         original array:
      idx:  0                     1             2               3            4    
          [member of family 1][mem of fam2][member of fam1][mem of fam 2][mem of fam 1]
          here  only idx 0,2,4 can be swapped so it cant be swapped with 1 or 2 
          so we just try to put the smallest numbers belonging to same family as left 
          as possible to get the lexico smallest 
          thats what the below loop does
        */
        for(int k=0;k<ind.size();k++){
            ans[ind[k]]=v[i+k].first;
        }
        i=j;
      }
      return ans;
    }
};