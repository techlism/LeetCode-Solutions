use std::collections::HashSet;
use std::collections::HashMap;
impl Solution {
    fn count_possible(tiles :&String, curr : String,
        flag :&mut HashMap<usize,i32>, possible : &mut HashSet<String>){
            
            for(i,c) in tiles.chars().enumerate(){
                if flag.get(&i) != Some(&1){
                    let mut new_curr = curr.clone();
                    new_curr.push(c);
                    flag.insert(i,1);
                    possible.insert(new_curr.clone());
                    Solution::count_possible(tiles,new_curr,flag,possible);
                    flag.insert(i,0);                    
                }
            }
    }
    pub fn num_tile_possibilities(tiles: String) -> i32 {
        let mut possible : HashSet<String> = HashSet::new();
        let mut flag : HashMap<usize,i32> = HashMap::new();
        Solution::count_possible(&tiles,"".to_string(), &mut flag, &mut possible);
        possible.len() as i32
    }
}