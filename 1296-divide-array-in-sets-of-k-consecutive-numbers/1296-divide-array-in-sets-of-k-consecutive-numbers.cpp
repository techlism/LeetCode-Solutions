class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int num : hand) freq[num]++;

        for (auto it : freq) {
            int start = it.first;
            while (freq[start] > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (freq[start + i] > 0) {
                        freq[start + i]--;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;        
    }
};