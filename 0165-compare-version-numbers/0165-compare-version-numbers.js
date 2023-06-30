/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
  const v1 = version1.split('.');
  const v2 = version2.split('.');
  let i = 0;
  let compare = [];
  while (v1.length > i || v2.length > i) {
    if (v1[i] && v2[i]) {
      const num1 = Number(v1[i]);
      const num2 = Number(v2[i]);
      if (num1 > num2)
        compare.push(1);
      else if (num1 < num2)
        compare.push(-1);
      else
        compare.push(0);
    }
    else if (!v1[i] && v2[i] && Number(v2[i]) !== 0) {
      compare.push(-1);
    } 
    else if (v1[i] && !v2[i] && Number(v1[i]) !== 0) {
      compare.push(1);
    }
    i++;
  }
  for (let val of compare) {
    if (val === 1) return 1;
    if (val === -1) return -1;
  }
  return 0;
};
