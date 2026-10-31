class Solution {
public:
    int rangeBitwiseAnd(int left, int right){
      if(left==right){
        return left;
      }
      long long diff=63-__builtin_clzll(left^right);
     long long mask=~((1LL<<(diff+1))-1);
      return (int)mask&left;
    }
};