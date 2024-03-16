/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *cur = &dummy;
        int prefixSum = 0;
        unordered_map<int, ListNode*> seen;

        while (cur) {
            prefixSum += cur->val;
            if (seen.find(prefixSum) != seen.end()) {
                cur = seen[prefixSum]->next;
                int p = prefixSum + cur->val;
                while (p != prefixSum) {
                    seen.erase(p);
                    cur = cur->next;
                    p += cur->val;
                }
                seen[prefixSum]->next = cur->next;
            } else {
                seen[prefixSum] = cur;
            }
            cur = cur->next;
        }
        
        return dummy.next;
    }
};
