class Solution {
private:
    void update(int &freq, int curr, int &ans){
        if(curr==ans) freq+=1;
        else if(curr > ans){
            ans = curr;
            freq = 1;
        }
    }
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq = 0;
        int ans = 0;
        unordered_map<int,int> map;
        for(auto num : nums) map[num]+=1;
        for(auto itr : map){
            int curr = itr.second;
            update(freq,curr,ans);
        }
        return freq * ans;
    }
};