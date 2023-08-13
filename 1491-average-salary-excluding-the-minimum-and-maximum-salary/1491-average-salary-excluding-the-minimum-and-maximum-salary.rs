impl Solution {
    pub fn average(salary: Vec<i32>) -> f64 {
        let min_max = (salary.iter().min().unwrap() + salary.iter().max().unwrap()) as f64;
        let sum = salary.iter().sum::<i32>() as f64; 
        let indx = (salary.len() - 2) as f64;
        return (sum - min_max) / indx;
    }
}
