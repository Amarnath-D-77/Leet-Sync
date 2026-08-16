class Solution {
public:
    int findNthDigit(int n){
        long long start=1;
        long long nums=9;
        long long length=1;
        while(n>nums*length){
            n-=nums*length;
            start*=10;
            length++;
            nums*=10;
        }
        long long ans=start+(n-1)/length;
        string s=to_string(ans);
        return s[(n-1)%length]-'0';
    }
};