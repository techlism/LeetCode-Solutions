function findSubsets(nums: number[], curr: number, currSubset: number[], ans: Set<string>): void {
    if (curr >= nums.length) {
        ans.add(JSON.stringify(currSubset));
        return;
    }
    // Include the current number
    currSubset.push(nums[curr]);
    findSubsets(nums, curr + 1, currSubset, ans);
    currSubset.pop();
    // Exclude the current number
    findSubsets(nums, curr + 1, currSubset, ans);
}

function subsetsWithDup(nums: number[]): number[][] {
    let ans: Set<string> = new Set();
    let currSubset: number[] = [];
    // sorting is required to avoid duplicacy.For eg. [4 1 4] and [4 4 1] are same as elements are same.
    nums.sort((a,b)=>a-b);
    findSubsets(nums, 0, currSubset, ans);
    // Convert the stringified subsets back to arrays
    return Array.from(ans).map(subset => JSON.parse(subset));
}