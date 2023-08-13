impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut ans = String::new();
        let mut carry = 0;
        let mut l1 = a.len() as i32 - 1;
        let mut l2 = b.len() as i32 - 1;
        while l1 >= 0 || l2 >= 0 || carry != 0 {
            let bit1 = if l1 >= 0 { a.chars().nth(l1 as usize).unwrap() } else { '0' };
            let bit2 = if l2 >= 0 { b.chars().nth(l2 as usize).unwrap() } else { '0' };
            let sum = (bit1 as u8 - '0' as u8) + (bit2 as u8 - '0' as u8) + carry;
            ans.insert(0, (sum % 2 + '0' as u8) as char);
            carry = sum / 2;

            l1 -= 1;
            l2 -= 1;
        }
        ans        
    }
}