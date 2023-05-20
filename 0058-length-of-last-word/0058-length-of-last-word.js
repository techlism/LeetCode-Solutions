/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    s=s.trim().split('').reverse().join('');
    console.log(s.length);
    if(s.length===1) return 1;
    let i=0;
    while(s[i]!=" " && i<s.length) i++;
    return i;
};