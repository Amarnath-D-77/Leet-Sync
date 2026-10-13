class Solution {
public:
    int closestTarget(vector<string>&words,string target,int startIndex){
       int n=words.size();
       vector<int>pos;
       int ans=INT_MAX;
       for(int i=0;i<n;i++){
        if(words[i]==target){
          pos.push_back(i);
          if(startIndex>i){
          ans=min(ans,n-startIndex+i);
          }
          else{
           ans=min(ans,n-i+startIndex);
          }
        }
       }
       if(pos.empty()){
        return -1;
       }
      
       for(int x:pos){
        cout<<abs(startIndex-x)<<" ";
        ans=min(ans,abs(startIndex-x));
       }
       return ans;
    }
};