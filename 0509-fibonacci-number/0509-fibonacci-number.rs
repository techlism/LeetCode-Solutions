impl Solution {
    fn fibonacci(n:i32, dp: &mut Vec<i32>)->i32{
        if n==1 {
            return 1;
        }
        if n==0 {
            return 0;
        }
        if dp[n as usize] != -1 {
            return dp[n as usize];
        }
        dp[n as usize] = Solution::fibonacci(n-1,dp) + Solution::fibonacci(n-2,dp);
        return dp[n as usize];
    }
    pub fn fib(n: i32) -> i32 {
        let mut dp : Vec<i32> = vec![-1;(n+1) as usize];
        Solution::fibonacci(n,&mut dp)
    }
}