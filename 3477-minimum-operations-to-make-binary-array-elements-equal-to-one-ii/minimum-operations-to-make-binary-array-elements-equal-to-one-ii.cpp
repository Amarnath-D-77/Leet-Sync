/*
 OBSERVATION:
            instead of toggling every window we just use cnt 
            to find out when we will need a flip 
             how do we know if want a toggle or not ?
                case 1:
                    nums[i]==0, 
                              I) if cnt is odd ,then we have flipped the 
                              current i idx odd number of times, which means it has turned to
                               1 then nums[i] has become 1 , 
                              we dont change if it is not equal 

                              II) if cnt is even, then we must toggle this because it is 0
                case 2:
                     nums[i]==1,
                              I) if cnt is odd that means it has toggled to  0 we must change it 
                              II) if cnt is even that means it has not changed it is still 1 so no 
                              change                          

*/
class Solution {
public:
    int minOperations(vector<int>&nums){
        int n=nums.size();
        int cnt=0;
        int flips=0;
        for(int i=0;i<n;i++){
            if(nums[i]==(cnt%2)){
              cnt++;
              flips++;
            }
        }
        return flips;
    }
};