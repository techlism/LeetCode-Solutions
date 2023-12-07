class Solution {
public:
    string largestOddNumber(string num) {
        // Basically we are just checking the farthest right value and 
        // then if it is odd then return from the start to this index
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        
        return "";
    }
};