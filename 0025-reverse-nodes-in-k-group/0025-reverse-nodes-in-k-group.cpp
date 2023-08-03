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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head){
            return head;
        }
        int cnt = 0;
        ListNode* temp = head;
        
        while(temp){
            temp = temp -> next;
            cnt++;
        }
        
        if(cnt < k){
            return head;
        }
        ListNode *next = nullptr;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        int count=0;
        while(curr && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next){
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
};