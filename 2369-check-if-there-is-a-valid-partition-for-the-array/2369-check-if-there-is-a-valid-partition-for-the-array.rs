impl Solution {
    fn check_partition(nums:&Vec<i32>,dp:&mut Vec<i8>,i : usize)->bool {
        if i==nums.len() {
            return true;
        }
        if dp[i] != -1 {
            return dp[i] != 0 ;
        }
        let mut result : bool = false;
        if i < nums.len() - 1 && nums[i]==nums[i+1] {
            result = Solution::check_partition(nums,dp,i+2);
        }
        if i < nums.len() - 2 {
            if (nums[i]==nums[i+1] && nums[i+1]==nums[i+2] ) || 
                (nums[i]+1==nums[i+1] && nums[i+1]==nums[i+2]-1) {
                result |= Solution::check_partition(nums,dp,i+3);
            }
        }
        dp[i]=result as i8;
        return result;
    }
    pub fn valid_partition(nums: Vec<i32>) -> bool {
        let mut dp : Vec<i8> = vec![-1;nums.len()];
        Solution::check_partition(&nums,&mut dp,0)
    }
}