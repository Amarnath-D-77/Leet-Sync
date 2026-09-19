class Solution {
public:
    vector<int>constructArray(int n,int k){
        vector<int>v(n);
        int l=1,r=k+1;
       for(int i=0;i<n;i++){
        if(i%2==0){
         v[i]=l++;
        }
        else{
         v[i]=r--;
        }
       }
       for(int i=k+1;i<n;i++){
        v[i]=i+1;
       }
       return v;
    }
};