impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        
        let trimmed = s.trim();
        let words: Vec<&str> = trimmed.split_whitespace().collect();

        if let Some(last_word) = words.last() {
            return last_word.len() as i32;
        } else {
            return 0;
        }        
    
    }
}