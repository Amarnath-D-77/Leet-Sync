class Solution {
public:
    int func(string s){
         int n=s.size(),cnt=0;
        string ss=s;
        sort(ss.begin(),ss.end());
        cout<<ss<<endl;
        if(!is_sorted(s.begin(),s.begin()+n-1)){
            sort(s.begin(),s.begin()+n-1);
           
              cnt++;
        }
        if(!is_sorted(s.begin()+1,s.begin()+n)){
            sort(s.begin()+1,s.begin()+n);
    
              cnt++;
        }
        if(!is_sorted(s.begin(),s.begin()+n-1)){
             sort(s.begin(),s.begin()+n-1);
      
              cnt++;
        }
          string s2(s.begin(),s.begin()+n-1);
      
        if(!is_sorted(s.begin(),s.end())){
              return -1;
        }
           return cnt;
    }
       int func1(string s){
         int n=s.size(),cnt=0;
        string ss=s;
        sort(ss.begin(),ss.end());
        cout<<ss<<endl;
         if(!is_sorted(s.begin()+1,s.begin()+n)){
            sort(s.begin()+1,s.begin()+n);
             
              cnt++;
        }
        if(!is_sorted(s.begin(),s.begin()+n-1)){
            sort(s.begin(),s.begin()+n-1);
   
              cnt++;
        }
        if(!is_sorted(s.begin()+1,s.begin()+n)){
             sort(s.begin()+1,s.begin()+n-1);
             
              cnt++;
        }
          string s2(s.begin(),s.begin()+n-1);
       
        if(!is_sorted(s.begin(),s.end())){
              return -1;
        }
           return cnt;
    }
     
    int minOperations(string s){
      int m1=func(s);
      int m2=func1(s);
      if(m1==-1){
        return m2;
      }
      if(m2==-1){
        return m1;
      }
      return min(m1,m2);
    }
};