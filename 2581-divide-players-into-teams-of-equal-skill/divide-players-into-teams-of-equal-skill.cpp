class Solution {
public:
    long long dividePlayers(vector<int>&skill){
        long long n=skill.size()/2;
        sort(skill.begin(),skill.end());
        long long  sum=0;
        for(int x:skill){
            sum+=x;
        }
        if(sum%n!=0){
            return -1;
        }
       long long  l=0,r=skill.size()-1,tar=sum/n;
       long long  ans=0;
       while(l<r){
        if(skill[l]+skill[r]!=tar){
            return -1;
        }
         ans+=(long long )skill[l]*skill[r];
         l++;
         r--;
       } 
        return ans;
    }
};