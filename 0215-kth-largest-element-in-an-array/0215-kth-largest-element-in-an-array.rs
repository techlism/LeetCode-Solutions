use std::collections::BinaryHeap;
use std::cmp::Reverse;
impl Solution{
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut heap = BinaryHeap::new();
        for &num in nums.iter().take(k as usize) {
            heap.push(Reverse(num));
        }
        for &num in nums.iter().skip(k as usize) {
            if let Some(&Reverse(top)) = heap.peek() {
                if top < num {
                    heap.pop();
                    heap.push(Reverse(num));
                }
            }
        }
        heap.peek().map_or(0, |x| x.0)
    }    
}

