class Solution {
// private:
//     int digitSum(int n){
//         int sum = 0;
//         while(n>0){
//             sum=sum+(n%10);
//             n=n/10;
//         }
//         return sum;
//     }
public:
//     int maximumSum(vector<int>& nums) {
//         unordered_multimap<int,int> map;
//         int ans=-1;
//         for(int i = 0;i<nums.size();i++){
//             map.insert(make_pair(digitSum(nums[i]),i));
//         }
//         for(auto itr : map){
//             auto range = map.equal_range(itr.first);

//             for (auto it = range.first; it != range.second; ++it) {
//                 if(itr.second!=it->second){
//                     ans=max(ans,(nums[itr.second]+nums[it->second]));
//                 }
//             }            
//         }
//         return ans;
//     }
// \U0001f446 The approach that I could come up with    
    int calculateSumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> maxNumBySum;

        int maxSum = -1;
        for (int num : nums) {
            int sum = calculateSumOfDigits(num);
            if (maxNumBySum.count(sum) > 0) {
                // that other number with same number of digits is present
                maxSum = max(maxSum, num + maxNumBySum[sum]);
            }
            // Else create a key-value pair in the map
            maxNumBySum[sum] = max(maxNumBySum[sum], num);
        }

        return maxSum;
    }    
};