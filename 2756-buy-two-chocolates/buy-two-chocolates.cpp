class Solution {
public:
    int buyChoco(vector<int>& prices,int money){
        sort(prices.begin(),prices.end());
        int cnt=0,mon=money;
        for(int x:prices){
            if(cnt>=2){
                break;
            }
          if(money-x>=0){
            money-=x;
            cnt++;
          }
        }
        if(cnt<=1){
            return mon;
        }
         return money;
    }
};