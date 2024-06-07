function findMaxConsecutiveOnes(nums: number[]): number {
    let ans = 0;
    let count = 0;
    for(let num of nums){
        if(num==1) count += 1;
        else {
            ans = Math.max(ans,count);
            count = 0;            
        }
    }
    return Math.max(ans,count);
};