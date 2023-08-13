impl Solution {
    pub fn check_straight_line(coordinates: Vec<Vec<i32>>) -> bool {
        let (x1, y1) = (coordinates[0][0], coordinates[0][1]);
        let (x2, y2) = (coordinates[1][0], coordinates[1][1]);

        for i in 2..coordinates.len() {
            let (x3, y3) = (coordinates[i][0], coordinates[i][1]);
            if (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1) {
                return false;
            }
        }
        return true;
    }
}