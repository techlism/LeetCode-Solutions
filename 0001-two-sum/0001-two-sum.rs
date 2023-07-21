use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        for i in 0..nums.len(){
            match map.get(&(target - nums[i])) {
                Some(&index) => return vec![i as i32, index],
                None => map.insert(nums[i], i as i32),
            };
        }
        return vec![];        
    }
}