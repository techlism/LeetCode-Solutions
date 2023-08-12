fn palindrome(chars: &Vec<char>, mut start: usize, mut end: usize) -> bool {
    while start <= end && end < chars.len() {
        if chars[start] != chars[end] {
            return false;
        }
        start += 1;
        end -= 1;
    }
    return true;
}
fn create_partition(s:&String , ans : &mut Vec<Vec<String>>, 
    path: &mut Vec<String>, index : usize ){
        if(index>=s.len()){
            ans.push(path.clone());
            return;
        }
        let chars : Vec<char> = s.chars().collect();
        for i in index..s.len() {
            if palindrome(&chars,index,i){
                path.push(chars[index..=i].iter().collect());
                create_partition(s,ans,path,i+1);
                path.pop();
            }
        }        
}
impl Solution {
    pub fn partition(s: String) -> Vec<Vec<String>> {
        let mut path : Vec<String> = Vec::new();
        let mut ans : Vec<Vec<String>> = Vec::new();
        create_partition(&s,&mut ans, &mut path,0);
        return ans;
    }
}