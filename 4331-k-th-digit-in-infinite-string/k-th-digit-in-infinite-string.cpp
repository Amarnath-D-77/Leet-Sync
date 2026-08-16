class Solution {
public:
    int kthDigit(long long k){
        // edge case : the first block has only 9 numbers 
        if(k<=9){
            return k;
        }
        k-=9;
        // except the edge every block has 10 numbers 
        long long st=10;
        long long num=90;
        long long len=2;
        while(k>len*num){
            k-=len*num;
            st*=10;
            num*=10;
            len++;
        }
       //calc the number: k-1/len gives how many numbers to jump from the start
       long long ans=st+(k-1)/len;
       //calc the block : for even or odd block 
       long long b=ans/10;
       if(b%2!=0){
        /* num to be subtracted is just the %block size because (n-1)/length gives the 
         numbers to jump from the start ,if we use it for odd condtions it would
         give wrong answers so we use %block size so that we can get how many numbers
         we have to subtract for that particular block 
         */

        long long num_to_be_subtracted=ans%10;
        ans=((10*b)+9)-num_to_be_subtracted;
       }
     string s=to_string(ans);
     return s[(k-1)%len]-'0';        
    }
};