class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>&intervals){
        sort(intervals.begin(),intervals.end(),[](const auto&a,const auto&b){
                return a[1]<b[1];
        });
        for(auto x:intervals){
            cout<<x[0]<<" "<<x[1]<<endl;
        }
        int curb=intervals[0][0]-1;
        int cnt=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=curb){
                cnt++;
                curb=intervals[i][1];
            }
        }
      return intervals.size()-cnt;
    }
};