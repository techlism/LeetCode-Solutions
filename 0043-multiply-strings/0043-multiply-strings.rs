impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        if num1 == "0" || num2 == "0" {
            return "0".to_string();
        }

        let l1 = num1.len() as i32 - 1;
        let l2 = num2.len() as i32 - 1;

        // Storing in reverse order.
        let mut res = vec![0; (l1 + l2 + 2) as usize];

        let num1_chars: Vec<char> = num1.chars().collect();
        let num2_chars: Vec<char> = num2.chars().collect();

        for i in (0..=l1).rev() {
            for j in (0..=l2).rev() {
                res[(i + j + 1) as usize] +=
                    (num1_chars[i as usize] as i32 - '0' as i32) * (num2_chars[j as usize] as i32 - '0' as i32);
                res[(i + j) as usize] += res[(i + j + 1) as usize] / 10;
                res[(i + j + 1) as usize] %= 10;
            }
        }

        let mut i = 0;
        let mut ans = String::new();
        // Remove the leading zeroes
        while i < res.len() && res[i] == 0 {
            i += 1;
        }
        while i < res.len() {
            ans.push_str(&res[i].to_string());
            i += 1;
        }

        ans
    }
}
