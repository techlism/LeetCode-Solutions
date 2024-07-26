class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last_index = 0;
        int ans = INT_MIN;
        int l = 0, r = 0;
        int n = fruits.size();
        int first = -1, second = -1;
        while (l <= r && r < n) {
            if (fruits[r] != first && fruits[r] != second) {
                first = fruits[last_index];
                second = fruits[r];
                l = last_index;
            }
            if (r > 0 && fruits[r] != fruits[r - 1])
                last_index = r;
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};