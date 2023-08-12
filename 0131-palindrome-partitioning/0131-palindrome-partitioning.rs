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
fn create_partition(chars: &Vec<char>, ans : &mut Vec<Vec<String>>, 
    path: &mut Vec<String>, index : usize ){
        if(index>=chars.len()){
            ans.push(path.clone());
            return;
        }        
        for i in index..chars.len() {
            if palindrome(&chars,index,i){
                path.push(chars[index..=i].iter().collect());
                create_partition(chars,ans,path,i+1);
                path.pop();
            }
        }        
}
impl Solution {
    pub fn partition(s: String) -> Vec<Vec<String>> {
        let mut path : Vec<String> = Vec::new();
        let mut ans : Vec<Vec<String>> = Vec::new();
        let chars : Vec<char> = s.chars().collect();
        create_partition(&chars,&mut ans, &mut path,0);
        return ans;
    }
}