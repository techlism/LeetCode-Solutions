class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> numfreq;
        for(auto num : nums) numfreq[num]++;
        map<int, vector<int> ,greater<int> > freqnum;
        for(auto nf : numfreq) freqnum[nf.second].emplace_back(nf.first);
        vector<int> ans;
        for(auto fn : freqnum){
            for(auto val : fn.second){
                if(ans.size() < k) ans.emplace_back(val);
            }
        }
        
        return ans;
    }
};