## Count Subarrays with Given XOR

**Given an array of integers `A` and an integer `B`, find the total number of subarrays having bitwise XOR of all elements equals to `B`.**

### Example 1:

**Input:**  
```
A = [4, 2, 2, 6, 4]
B = 6
```

**Output:**  
```
4
```

**Explanation:**  
The subarrays with XOR equal to 6 are:
- [4, 2]
- [2, 6]
- [4, 2, 2, 6, 4] (entire array)
- [6]

### Your Task:
You just have to complete the function `countSubarraysWithXOR()` which takes two arguments, an array `A` and an integer `B`, and returns the total number of subarrays having bitwise XOR of all elements equal to `B`.

### Expected Time Complexity: 
```
O(N)
```

### Expected Auxiliary Space: 
```
O(N)
```

### Constraints:
- `1 <= |A| <= 10^5`
- `0 <= A[i], B <= 10^9`

---
