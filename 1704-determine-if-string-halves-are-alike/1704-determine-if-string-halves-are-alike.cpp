class Solution {
public:
    bool halvesAreAlike(string s) {
        int countv1=0;
        int countv2=0;
        for(int i=0;i<s.length();i++){
            if(i<=s.length()/2 -1 && (s[i]=='a'||s[i]=='e'||  s[i]=='i' || s[i]=='o' || s[i]=='u'||s[i]=='A'||s[i]=='E'||  s[i]=='I' || s[i]=='O' || s[i]=='U' )){
                countv1++;
            }
            if(i>=s.length()/2 && (s[i]=='a'||s[i]=='e'||  s[i]=='i' || s[i]=='o' || s[i]=='u'||s[i]=='A'||s[i]=='E'||  s[i]=='I' || s[i]=='O' || s[i]=='U' )){
                countv2++;
            }
        }
        if(countv1 == countv2){
            return true;
        }
        return false;        
    }
};