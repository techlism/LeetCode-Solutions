class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;
        int ans = 0;
        
        for (char ch : s) {
            freq[ch]++;
        }
        
        unordered_set<int> usedFreq;
        for (const auto& it : freq) {
            int count = it.second;
            while (usedFreq.find(count) != usedFreq.end()) {
                ans++;
                count--;
            }
            if (count != 0) {
                usedFreq.insert(count);
            }
        }
        
        return ans;
    }
};
