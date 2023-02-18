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
    ListNode* partition(ListNode* head, int x) {
        //Creating with dummy nodes to easily join them later
        ListNode * less = new ListNode(0);
        ListNode * greater = new ListNode(0);
        //Basically less->next is lessTail and greater->next is greaterTail
        ListNode * lessTail=less;
        ListNode * greaterTail=greater;
        while(head){
            if(head->val < x){
                lessTail->next=head;
                lessTail=lessTail->next;
            }
            else{
                greaterTail->next=head;
                greaterTail=greaterTail->next;
            }
            head=head->next;
        }
        lessTail->next=greater->next;
        greaterTail->next=nullptr;
        //skipping the dummy node
        return less->next;
    }
};