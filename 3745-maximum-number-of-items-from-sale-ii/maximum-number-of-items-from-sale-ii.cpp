class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items,int budget){
        int low=2e9;
        int maxf=0;
        for(auto &item:items){
            if(low>item[1]){
                low=item[1];
            }
            if(maxf<item[0]){
                maxf=item[0];
            }
        }
        vector<int>freq(maxf+1,0);
        for(auto &item:items){
            freq[item[0]]++;
        }
        vector<int>fctrs(maxf+1,0);
        for(int i=1;i<=maxf;i++){
         if(freq[i]==0){
            continue;
         }
         for(int j=i;j<=maxf;j+=i){
            fctrs[i]+=freq[j];
         }
        }
        vector<pair<int,int>>deals;
        for(int i=0;i<items.size();i++){
            int pr=items[i][1];
            int fct=fctrs[items[i][0]]-1;
            if(fct>0 && pr<2*low){
                deals.push_back({pr,fct});
            }
        }
        sort(deals.begin(),deals.end());
        int tot=0;
        int curb=budget;
        for(auto &p:deals){
            int pr=p.first;
            int fr=p.second;
            if(curb>=pr){
                int mini=min(fr,curb/pr);
                curb-=mini*pr;
                tot+=2*mini;
            }
        }
        tot+=curb/low;

        return tot;
    }
};