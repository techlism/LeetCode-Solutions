use std::cmp;
impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        for i in 0..accounts.len() {
            ans = cmp::max(ans,accounts[i].iter().sum());            
        }
        return ans;
    }
}