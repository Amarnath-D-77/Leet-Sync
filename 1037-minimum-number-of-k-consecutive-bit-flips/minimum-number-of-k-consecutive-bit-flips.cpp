/*
 OBSERAVATION:
             KEY:
                we are greedily changing the window whenever there is a zero, 
                so only the last window must have remaining zeroes which must be toggled ,
                we return -1 only when we have to change but there is no window that is 
                 if(i+k>nums.size()){
                    return -1;
                }

             1.instead of toggling the window every time we encounter a 
               zero will cost time,so we use queue to eliminate the index
               which is expired when we reach out of the window 
               [0 1 2]3 4--> 0[1 2 3 ]4 in this only zero got out so 
               queue is necessary 
             2. how do we know if want a toggle or not ?
                case 1:
                    nums[i]==0, 
                              I) if q.size() is odd ,then we have flipped the 
                              current i idx odd number of times, which means it has turned to
                               1 then nums[i] has become 1 , 
                              we dont change if it is not equal 

                              II) if q.size() is even, then we must toggle this because it is 0
                case 2:
                     nums[i]==1,
                              I) if q.size() is odd that means it has toggled to  0 we must change it 
                              II) q.size() is even that means it has not changed it is still 1 so no 
                              change                          
*/
class Solution {
public:
    int minKBitFlips(vector<int>& nums,int k){
        int flips=0;
        queue<int>q;
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && i>=q.front()+k){
              q.pop();
            }       
            if(nums[i]==(q.size()%2)){
                if(i+k>nums.size()){
                    return -1;
                }
                q.push(i);
                flips++;
            }      
             }
        return flips;
    }
};