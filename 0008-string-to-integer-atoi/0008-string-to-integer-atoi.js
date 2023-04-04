/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    const ans = Number.parseInt(s)
    if(ans){
        // Less than INT_MIN(32 bit)
        if(ans <= -2147483648 ) 
            return -2147483648 ;
        // Greater than INT_MAX(32 bit)
        else if (ans >= 2147483647) 
            return 2147483647;
        else
            return ans;
    }
    else 
        return 0;
};