impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let rows : i32 = (matrix.len()) as i32;
        let columns : i32 = (matrix[0].len()) as i32;
        let mut start : i32 = 0;
        let mut end : i32 = (rows * columns - 1) as i32;
        while start <= end {
            let mid = start + (end - start) / 2;
            let val : i32 = matrix[mid as usize/columns as usize][mid as usize % columns as usize];
            if  val == target {
                return true;
            }
            else if val < target {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return false;
    }
}