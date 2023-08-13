impl Solution {
    pub fn judge_circle(moves: String) -> bool {
        // let mut right = 0 ;
        // let mut left = 0 ;
        // let mut top =  0 ;
        // let mut down = 0 ;
        // for mov in moves.chars() {
        //     if mov== 'R'{
        //         right+=1;
        //     }
        //     if mov=='L' {
        //         left+=1;
        //     }
        //     if mov=='U' {
        //         top+=1;
        //     }
        //     if mov=='D' {
        //         down+=1;
        //     }
        // }
        // if (right==left) && (top==down) {
        //     return true;
        // }
        // return false;
        // My Solution \U0001f446. A bit optimized one \U0001f447
        let mut horizontal = 0;
        let mut vertical = 0;

        for mov in moves.chars() {
            match mov {
                'R' => horizontal += 1,
                'L' => horizontal -= 1,
                'U' => vertical += 1,
                'D' => vertical -= 1,
                // if none of the above condition matches
                _ => (),
            }
        }

        horizontal == 0 && vertical == 0        
    }
}