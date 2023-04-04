/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head ;
        while(slow && fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                while(slow != head){
                    // The only part that was tricky
                    slow = slow -> next;
                    head = head -> next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};