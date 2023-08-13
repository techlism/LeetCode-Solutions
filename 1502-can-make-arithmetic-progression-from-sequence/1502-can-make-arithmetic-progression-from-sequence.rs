impl Solution {
    pub fn can_make_arithmetic_progression(arr:Vec<i32>) -> bool {
        let mut arr_dup = arr.clone();
        arr_dup.sort();
        let mut diff = 0;
        for i in 0..arr_dup.len()-1 {
            if i==0 {
                diff = arr_dup[i+1] - arr_dup[i];
            }
            else{
                if (arr_dup[i+1] - arr_dup[i]) != diff {
                    return false;
                }
            }
        }
        return true;
    }
}