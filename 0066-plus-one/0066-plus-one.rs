impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut ans : Vec<i32> = Vec::new();
        let mut carry = 0;
        
        for i in (0..digits.len()).rev() {
            let mut val;
            if i == digits.len() -1 {
                val = digits[i] + carry + 1;
            }
            else {
                val = digits[i] + carry ;
            }
            ans.insert(0,val%10);
            carry=val/10;
        }
        if carry != 0 {
            ans.insert(0,carry);
        }
        return ans;
    }
}