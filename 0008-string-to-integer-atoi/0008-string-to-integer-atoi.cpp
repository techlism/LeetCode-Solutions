class Solution {
public:
    int myAtoi(string s) {
        stringstream st(s);
        int n=0;
        st>>n;
        return n;        
    }
};