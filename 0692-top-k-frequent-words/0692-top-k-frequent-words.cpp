class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> wordFreq;
        map<int,set<string>,greater<int>> freqWords;
        for(auto word: words) wordFreq[word]++;
        for(auto freq : wordFreq) freqWords[freq.second].insert(freq.first);
        vector<string> ans;
        for(auto fw : freqWords){
                for(auto setval : fw.second){
                    if(ans.size()<k) ans.push_back(setval);
                    else return ans;
                }
        }
        return ans;
    }
};