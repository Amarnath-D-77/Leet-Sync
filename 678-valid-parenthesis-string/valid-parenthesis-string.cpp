class Solution {
public:
    bool checkValidString(string s){
         int maxi=0;
         int mini=0;
         for(char c:s){
            if(c=='('){
                maxi++;
                mini++;
            }
            else if(c==')'){
                maxi--;
                mini--;
            }
            else{
                maxi++;
                mini--;
            }
            if(mini<0){
               mini=0;
            }
            if(maxi<0){
                return false;
            }
         }
        if(mini==0){
            return true;
        }
        return false;
    }
};