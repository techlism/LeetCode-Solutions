## Flattening a Linked List

**Medium Accuracy:** 51.53%  
**Submissions:** 142K+  
**Points:** 4

*Get Internship at GfG by submitting your Entries in: Data Science Blogathon*

---

### Problem Statement

Given a Linked List of size `N`, where every node represents a sub-linked-list and contains two pointers:
1. `next` pointer to the next node,
2. `bottom` pointer to a linked list where this node is head.

Each of the sub-linked-list is in sorted order. Flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

**Note:** The flattened list will be printed using the `bottom` pointer instead of the `next` pointer. For more clarity have a look at the `printList()` function in the driver code.

### Examples

**Example 1:**

```
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22    35
|           |     | 
8          50    40
|                 | 
30               45

Output: 
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 30 -> 35 -> 40 -> 45 -> 50

Explanation:
The resultant linked list has every node in a single level.
(Note: | represents the bottom pointer.)
```

**Example 2:**

```
Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              

Output: 
5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50

Explanation:
The resultant linked list has every node in a single level.
(Note: | represents the bottom pointer.)
```

### Your Task

You do not need to read input or print anything. Complete the function `flatten()` that takes the head of the linked list as input parameter and returns the head of flattened linked list.

### Expected Time Complexity

- \(O(N*N*M)\)

### Expected Auxiliary Space

- \(O(N)\)

### Constraints

- \(0 \leq N \leq 50\)
- \(1 \leq M_i \leq 20\)
- \(1 \leq\) Element of linked list \(\leq 10^3\)

---
GFG -- https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

