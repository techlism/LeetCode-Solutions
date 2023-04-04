class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>mins;
        for(auto s : timePoints){
            int hours = (s[0]-'0') * 10 + (s[1]-'0');
            int minutes = (s[3]-'0') * 10 + (s[4]-'0') + (hours * 60);
            mins.emplace_back(minutes);
        }
        sort(mins.begin(),mins.end());
        int ans = INT_MAX;
        for(int i = 1;i<mins.size();i++){
            ans=min(ans,mins[i]-mins[i-1]);
        }
        int last=(mins[0]+1440)-mins[mins.size()-1];
        ans=min(ans,last);

        return ans;
    }
};