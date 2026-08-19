class Solution {
public:
    int maxNumberOfFamilies(int n,vector<vector<int>>&reservedSeats){
        map<int,vector<int>>v;
        for(auto x:reservedSeats){
            v[x[0]-1].push_back(x[1]);
        }
        int tot=(n-v.size())*2;
         for(auto x:v){
            bool check1=true;
            bool check2=true;
            bool check3=true;
            for(int y:x.second){
                 if(y==2 || y==3 || y==4 || y==5 ){
                    check1=false;
                 }  
                 if(y==4 || y==5 || y==6 || y==7){
                    check2=false;
                 }  
                 if(y==6 || y==7 || y==8 || y==9){
                    check3=false;
                 }  
            }
             if(check1){
                tot++;
                check2=false;
             }
             if(check2){
                tot++;
                check3=false;
             }
            if(check3){
               tot++;
             }  
        }
        return tot;
    }
};