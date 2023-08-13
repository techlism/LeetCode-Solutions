impl Solution {
    pub fn array_sign(nums: Vec<i32>) -> i32 {
        let mut neg : i32 = 0;
        for i in 0..nums.len() {
            if nums[i]==0 {
                return 0;
            }
            else if nums[i] < 0 {
                neg+=1;
            }
        }
        if neg%2 == 0 {
            return 1;
        }
        -1
    }
}