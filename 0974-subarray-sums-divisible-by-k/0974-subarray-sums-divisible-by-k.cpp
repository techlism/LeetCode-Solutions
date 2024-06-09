class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : nums) {
            // this is the shit that you have to care about
            prefix = (prefix + a % k + k) % k;
            res += count[prefix]++;
        }
        return res;        
    }
};