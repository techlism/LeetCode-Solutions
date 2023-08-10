impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> bool {
        let mut low = 0;
        let mut high = nums.len() as i32 - 1;

        while low <= high {
            let mid = (low + high) / 2;

            // Check if the middle element is the target
            if nums[mid as usize] == target {
                return true;
            }

            // Handle the case where nums[low] and nums[mid] are equal
            if nums[low as usize] == nums[mid as usize] {
                low += 1;  // Move the low index one step ahead
                continue;  // Skip the rest of the loop and start the next iteration
            }

            // Check which half of the array is sorted
            if nums[low as usize] <= nums[mid as usize] {
                // Left half is sorted

                if nums[low as usize] <= target && target <= nums[mid as usize] {
                    high = mid - 1;  // Target is in the left half, update high index
                } else {
                    low = mid + 1;   // Target is in the right half, update low index
                }
            } else {
                // Right half is sorted

                if nums[mid as usize] <= target && target <= nums[high as usize] {
                    low = mid + 1;   // Target is in the right half, update low index
                } else {
                    high = mid - 1;  // Target is in the left half, update high index
                }
            }
        }

        false  // If target is not found, return false
    }
}
