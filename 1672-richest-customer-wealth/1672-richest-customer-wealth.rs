use std::cmp;
impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        for i in 0..accounts.len() {
            let wealth = accounts[i].iter().sum();
            ans = cmp::max(ans,wealth);            
        }
        ans
    }
}