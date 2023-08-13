impl Solution {
    pub fn is_monotonic(nums: Vec<i32>) -> bool {
        let mut incr : i32 = 0;
        let mut decr : i32 = 0;
        for i in 0..nums.len()-1 {
            if nums[i] > nums[i+1] {
                decr+=1;
            }
            else if nums[i] < nums[i+1] {
                incr+=1;
            }
        }
        // println!("{incr} {decr}");
        if incr !=0 && decr != 0 {
            return false;
        }
        return true;
    }
}