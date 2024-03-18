/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    // let ans = [];
    // for(let i=0;i<arr.length;i++){
    //     let output = fn(arr[i],i);
    //     ans.push(output);
    // }
    // return ans;
    return arr.map((element,index)=>fn(element,index));
};