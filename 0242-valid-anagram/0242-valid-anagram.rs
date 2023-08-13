impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut chars: Vec<char> = s.chars().collect();
        chars.sort();
        let mut chars_2 : Vec<char> = t.chars().collect();
        chars_2.sort();
        if chars.len() != chars_2.len(){
            return false;
        } 
        for i in 0..chars.len() {
            if chars[i] != chars_2[i] {
               return false; 
            } 
        }
        return true;
    }
}