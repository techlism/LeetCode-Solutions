/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    if(n == 0){
        return arr;
    }
    
    let answer = [];
    
    for(let val of arr){
        
        if(Array.isArray(val)){
            answer.push(...flat(val, n-1));
        }
        else{
            answer.push(val);
        }
    }
    
    return answer;    
};