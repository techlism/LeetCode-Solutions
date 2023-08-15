impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        return ((high - low) >> 1) + ((low | high) & 1); 
    }
}