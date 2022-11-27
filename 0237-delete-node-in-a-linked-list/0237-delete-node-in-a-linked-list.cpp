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
    void deleteNode(ListNode* node) {
        
        //technically we are not deleting that given Node . we are just de-referencing it.
     ListNode * nextnode=node->next;
        node->val=nextnode->val;
        node->next=nextnode->next;
        nextnode->next=NULL;
        delete(nextnode);
        
    }
};
