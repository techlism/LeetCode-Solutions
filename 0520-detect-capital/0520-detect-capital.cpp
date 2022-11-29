class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i=0;i<word.length()-1;i++){
            if(i+2<word.length()){
            if(word[i]>=65 && word[i]<=90 && (word[i+1]>=65 && word[i+1]<=90) && word[i+2]>=97){
                return false;
            }                
            }

            if(word[i]>=97 && (word[i+1]>=65 && word[i+1]<=90)){
                return false; 
            }
               
        }
        return true;
    }
};