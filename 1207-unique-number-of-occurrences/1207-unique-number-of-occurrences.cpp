class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        
        for(auto num : arr) freq[num]++;
        unordered_set<int> fr;
        for(auto itr : freq) fr.insert(itr.second);
        return fr.size() == freq.size();
    }
};