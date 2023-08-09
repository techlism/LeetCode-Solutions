use std::collections::HashMap;
impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut map : HashMap<char,(i32,usize)> = HashMap :: new();
        
        for(i ,ch ) in s.chars().enumerate() {
            if !map.contains_key(&ch){
                map.insert(ch,(1,i));
            }
            else{
                if let Some(entry) = map.get_mut(&ch){
                    entry.0 += 1;
                }
            }
        }
        let mut ans = std :: usize :: MAX;
        for(_,&(freq,idx)) in &map {
            if freq == 1 {
                ans = std::cmp::min(ans,idx);
            }
        }
        
        if ans == std::usize::MAX {
            -1
        }
        else {
            ans as i32
        }
    }
}