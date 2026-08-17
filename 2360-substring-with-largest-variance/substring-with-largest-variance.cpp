/*
 OBSERVATION:
          KEY: 
             The question asks us to find the difference between the occurence of two 
             characters if there are only one character then variance is 0 ,
             so the algorithm handles that as an edge case and the remaining code
             calculates the longest subbray of +1 which has atleast one -1 which is 
             the minor character
            we consider the major characters as +1 and minor characters as -1\
             and we apply kadane to it 
            STATES:
                  1.dp_has_no_minor- tracks the longest streak of +1's ,
                  it resets to 0 when the minor character appears,

                  2.dp_has_minor-this is the actual substring 
                      CASE1:
                           either append the -1 to the before calculated legal string 
                      CASE 2:
                           continue with the brand new non legal string 
 */
class Solution {
public:
    int largestVariance(string s){
        vector<int>freq(26);
        for(char c:s){
            freq[c-'a']++;
        }
        int maxi=0;
        for(char major='a';major<='z';major++){
            for(char minor='a';minor<='z';minor++){
              if(major==minor||
                 freq[major-'a']==0 || freq[minor-'a']==0){
                    continue;
                 }
                 int dp_has_no_minor=0;
                 int dp_has_minor=-1e9;
                 for(char c:s){
                    if(c==major){
                        dp_has_minor++;
                        dp_has_no_minor++;
                    }
                    else if(c==minor){
                     dp_has_minor=max(dp_has_no_minor-1,dp_has_minor-1);
                     dp_has_no_minor=0;
                    }
                    maxi=max(maxi,dp_has_minor);
                 }
            }
        }
    return maxi;
    }
};