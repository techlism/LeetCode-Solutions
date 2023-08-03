class Solution {
public:
    int titleToNumber(string columnTitle) {
        int columnNumber = 0;
        int n = columnTitle.length();

        for (int i = n - 1; i >= 0; i--) {
            int numericValue = columnTitle[i] - 'A' + 1;
            columnNumber += numericValue * pow(26, n - i - 1);
        }

        return columnNumber;      
    }
};