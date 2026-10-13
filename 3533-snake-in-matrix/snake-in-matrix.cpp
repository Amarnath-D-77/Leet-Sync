class Solution {
public:
    int finalPositionOfSnake(int n,vector<string>&commands){
        int i=0,j=0;
        for(string s:commands){
            if(s=="RIGHT"){
              j+=1;
            }
            else if(s=="LEFT"){
                j-=1;
            }
            else if(s=="DOWN"){
                i+=1;
            }
            else{
                i-=1;
            }
        }
        return (i*n)+j;
    }
};