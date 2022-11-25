class Solution {
public:
    int lengthOfLastWord(string s) {
        int countSpaces=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                countSpaces++;
            }
            else{
                break;
            }
        }
        int count=0;
        for(int i=s.length()-1-countSpaces;i>=0;i--){
            if(s[i]!=' '){
                count++;
            }
            if(s[i]==' ' && s[i+1]!=' '){
                break;
            }
        }
        return count;
    }
};