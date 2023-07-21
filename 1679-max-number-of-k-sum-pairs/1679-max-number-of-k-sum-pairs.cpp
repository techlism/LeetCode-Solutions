class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        int s = 0, e = nums.size()-1;
        while(s < e) {
            long long sum = nums[s] + nums[e];
            if(sum==k){
                s++;
                e--;
                count++;
            }
            else if(sum < k) s++;
            else e-- ;
        }
        return count;
    }
};