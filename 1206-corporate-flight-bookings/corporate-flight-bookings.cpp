class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>&bookings,int n){
         int c=bookings.size();
        vector<int>diff(n+1,0);
        for(int i=0;i<c;i++){
            diff[bookings[i][0]-1]+=bookings[i][2];
            diff[bookings[i][1]]-=bookings[i][2];
        }
       int cur=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            cur+=diff[i];
          ans.push_back(cur);
        }
        return ans;
    }
};