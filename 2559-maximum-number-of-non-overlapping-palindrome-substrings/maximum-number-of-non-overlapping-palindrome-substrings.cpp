class Solution {
public:
    int maxPalindromes(string s,int k){
        int n=s.size();
        struct Interval{
            int start,end;
        };
        vector<Interval>v;
       for(int i=0;i<n;i++){
        // odd palindromes;
         int st=i,end=i;
         while(st>=0 && end<n && s[st]==s[end]){
            if(end-st+1>=k){
            v.push_back({st,end});
            }
            st--;
            end++;
         }
         // even palindromes
         st=i,end=i+1;
          while(st>=0 && end<n && s[st]==s[end]){
             if(end-st+1>=k){
            v.push_back({st,end});
            }
            st--;
            end++;
         }
       }
       sort(v.begin(),v.end(),[](const Interval&a,const Interval&b){
          if(a.end!=b.end){
            return a.end<b.end;
          }
          return a.start>b.start;
       });
       int cur=-1,ans=0;
       for(int i=0;i<v.size();i++){
        if(cur<v[i].start){
          ans++;
          cur=v[i].end;
        }
       }
       return ans;
    }
};