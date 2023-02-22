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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *ans = new ListNode(0); // created dummy(ans) node
        ans->next = head;
        ListNode *prev = ans; // intialising prev pointer on dummy node
        
        //The thing is left and right are positions not nodes(So reach to node prev left pos)
        for(int i = 0; i < left - 1; i++){
            prev = prev->next;            
        }

        // curr pointer will be just after prev
        ListNode *curr = prev->next; 
        
        // reversing till the right position
        for(int i = 0; i < right - left; i++){
            // forw pointer will be after curr
            ListNode * forw = curr->next; 
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return ans->next;        
    }
};