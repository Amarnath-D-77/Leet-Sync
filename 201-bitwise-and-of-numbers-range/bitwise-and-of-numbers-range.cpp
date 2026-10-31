class Solution {
public:
    int rangeBitwiseAnd(int left, int right){
        int l=left,r=right;
        int shift=0;
        while(l!=r && l>0){
            l=l>>1;
            r=r>>1;
            shift++;
        }
        return l<<shift;
    }
};