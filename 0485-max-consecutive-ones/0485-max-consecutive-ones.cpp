class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // stack<int> s;
        // stack<int> empty;
        // int ans  = 0;
        // for(auto num : nums){
        //     if((s.empty() && num == 1) || (!s.empty() && num==1)) s.push(num);
        //     if(!s.empty() && num == 0 ){
        //         ans = max(ans,int(s.size()));
        //         s=empty;
        //     }
        // }
        // return max(ans,int(s.size()));
        
        // More simpler approach
        int maxCount = 0, count = 0;
        for (auto n : nums) {
            if (n == 1) maxCount = max(++count, maxCount);
            else count = 0;
        }
        return maxCount;        
    }
};