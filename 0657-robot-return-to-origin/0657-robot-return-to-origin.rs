impl Solution {
    pub fn judge_circle(moves: String) -> bool {
        let mut right = 0 ;
        let mut left = 0 ;
        let mut top =  0 ;
        let mut down = 0 ;
        for mov in moves.chars() {
            if mov== 'R'{
                right+=1;
            }
            if mov=='L' {
                left+=1;
            }
            if mov=='U' {
                top+=1;
            }
            if mov=='D' {
                down+=1;
            }
        }
        if (right==left) && (top==down) {
            return true;
        }
        return false;
    }
}