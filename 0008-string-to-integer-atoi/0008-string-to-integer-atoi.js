/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    if(Number.parseInt(s)){
        // Less than INT_MIN(32 bit)
        if(Number.parseInt(s) <= -2147483648 ) 
            return -2147483648 ;
        // Greater than INT_MAX(32 bit)
        else if (Number.parseInt(s) >= 2147483647) 
            return 2147483647;
        else
            return Number.parseInt(s);
    }
    else 
        return 0;
};