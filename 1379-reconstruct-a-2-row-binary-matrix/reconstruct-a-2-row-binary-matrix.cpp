class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum){
        int n=colsum.size();
        vector<vector<int>>v(2,vector<int>(n,0));
        int cnt=0,cnt1=0;
        for(int i=0;i<n;i++){
            if(colsum[i]==1){
             if(cnt<=cnt1){
                v[0][i]=1;
                cnt++;
             }
             else if(cnt1<=cnt){
                v[1][i]=1;
                cnt1++;
             }
            }
            else if(colsum[i]==2){
                    v[0][i]=1;
                    v[1][i]=1;
                    cnt++;
                    cnt1++;
                }
        }
        for(int i=0;i<n;i++){
            if(v[0][i]!=v[1][i]){
                if(cnt>upper && v[0][i]==1){
                    int temp=v[0][i];
                    v[0][i]=v[1][i];
                    v[1][i]=temp;
                    cnt--;
                    cnt1++;
                }
                else if(cnt1>lower && v[1][i]==1){
                    int temp=v[0][i];
                    v[0][i]=v[1][i];
                    v[1][i]=temp;
                    cnt++;
                    cnt1--;
                    }
            }
        }
        if(cnt==upper && cnt1==lower){
            return v;
        }
        return {};
    }
};