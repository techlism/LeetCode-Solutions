class Solution {
// Time Complexity : O(NLOGN)
// Space Complexity : O(N) + O(N) = O(N)
public:
    string frequencySort(string s) {
        unordered_map <char,int> ctof;
        map<int, string,greater<int> >fts;
        string ans="";
        for(auto ch : s) ctof[ch]+=1;
        for(auto el : ctof) fts[el.second].push_back(el.first);
        for(auto str : fts){
            auto chArr = str.second;
            for (auto ch : chArr){
                int freq = str.first;                
                 while(freq > 0){
                    ans+=ch;
                    freq--;
                }               
            }
        }
        return ans;
    }
};