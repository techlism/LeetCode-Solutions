class Solution {
public:
    string removeTrailingZeros(string num) {
        int e = num.length() - 1;
        while(e>0){
            if(num[e]=='0') num.pop_back();
            if(num[e]!=0) return num;
            e--;
        }
        return num;
    }
};