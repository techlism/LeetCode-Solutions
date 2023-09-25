impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let mut sum1: u8 = 0;
        let mut sum2: u8 = 0;
        for i in s.chars() {
            sum1+= i as u8;
        }
        for i in t.chars() {
            sum2+= i as u8;
        }
        return (sum2 - sum1) as char;
    }
}