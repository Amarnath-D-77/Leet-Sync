class Solution {
public:
    string maxSumOfSquares(int num, int sum){
        int maxi=9;
        string s="";
        while(s.empty() || s.size()<num){
            if(sum-maxi>=0 && maxi>=0){
            s+=to_string(maxi);
            sum-=maxi;
            }
            else{
                maxi--;
            }
        }
        if(sum!=0){
            return "";
        }
       
        return s;
    }
};