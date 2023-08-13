impl Solution {
    pub fn cal_points(operations: Vec<String>) -> i32 {
        let mut stack : Vec<i32> = Vec::new();
        for i in 0..operations.len() {
            let top = stack.len() - 1 ;
            if operations[i] == "C" && stack.len() > 0{
                stack.pop();
            }
            else if operations[i] == "D" && stack.len() > 0{
                stack.push(stack[top] * 2);
            }
            else if operations[i] == "+" && stack.len() >= 2 {
                stack.push(stack[top] + stack[top-1]);
            }
            else{
                if let Ok(num) = operations[i].parse::<i32>() {
                        stack.push(num);
                }
            }
        }
        return stack.iter().sum() ;
    }
}