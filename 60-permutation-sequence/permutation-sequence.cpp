class Solution {
public:
    string getPermutation(int n,int k){
         int fact=1;
         vector<int>num;
         for(int i=1;i<n;i++){
             fact=fact*i;
             num.push_back(i);
         }
         num.push_back(n);
         k-=1;
         string ans="";
         for(int i=0;i<n;i++){
            int idx=k/fact;
            ans+=to_string(num[idx]);
            num.erase(num.begin()+idx);
            if(num.size()>0){
                k%=fact;
                fact=fact/num.size();
            }
         }
        return ans;
    }
};