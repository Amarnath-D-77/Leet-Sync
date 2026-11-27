class Solution{
public:
    int next(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            sum+=(d*d);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n){
        set<int>s;
        while(n!=1 && !s.count(n)){
            s.insert(n);
            n=next(n);
        }
       return n==1;
    }
};