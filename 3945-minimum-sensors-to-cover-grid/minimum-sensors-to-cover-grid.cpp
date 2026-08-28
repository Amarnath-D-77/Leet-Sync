class Solution {
public:
    int minSensors(int n, int m, int k){
    
        int rows=ceil((double)n/((k*2)+1));
        int cols=ceil((double)m/((k*2)+1));
        cout<<rows<<" "<<cols<<endl;
       
        return rows*cols;
    }
};