/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    s=s.trim().split('').reverse().join('');
    let i=0;
    while(s[i]!=" " && i<s.length) i++;
    return i;
};