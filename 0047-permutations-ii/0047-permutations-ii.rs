use std::collections::HashSet;
fn permute(nums: &mut Vec<i32>, ans: &mut Vec<Vec<i32>>, index: usize) {
    if index >= nums.len() {
        ans.push(nums.clone());
        return;
    }
    let mut used = HashSet::new(); // Track used elements at each index
    for i in index..nums.len() {
        if used.contains(&nums[i]) {
            continue;
        }
        used.insert(nums[i]);
        nums.swap(i, index);
        permute(nums, ans, index + 1);
        nums.swap(i, index);
    }
}

impl Solution {
    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let mut nums = nums;
        permute(&mut nums, &mut ans, 0);
        ans
    }
}
