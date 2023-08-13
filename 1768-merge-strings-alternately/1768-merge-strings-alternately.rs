impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let mut ans: String = String::from("");
        let mut len1: usize = 0;
        let mut len2: usize = 0;
        // The solution is much more simpler than I thought
        // Time Complexity : O(n) [n is max of len1 and len2]
        while len1 < word1.len() || len2 < word2.len() {
            if len1 < word1.len() {
                ans.push(word1.chars().nth(len1).unwrap());
                len1 += 1;
            }
            if len2 < word2.len() {
                ans.push(word2.chars().nth(len2).unwrap());
                len2 += 1;
            }
        }
        
        ans
    }
}
