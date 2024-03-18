/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans  = [];
    arr.map((el, index)=>{
        if(fn(el,index)) ans.push(el);
    })
    return ans
};