class Solution {
public:
    char findTheDifference(string s, string t) {
       long long sum1=0, sum2=0;
        for(int i=0;i<s.length();i++){
            sum1=sum1+s[i];
        }
        for(int j=0;j<t.length();j++){
            sum2=sum2+t[j];
        }
        return (char)(sum2-sum1);
    }
};