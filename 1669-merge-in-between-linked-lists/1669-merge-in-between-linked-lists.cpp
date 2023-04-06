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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * l1a = list1;
        ListNode * l1b = list1;
        ListNode * l2  = list2;
        for(int i=1;i<a;i++){
            if(l1a->next) l1a = l1a->next;
        }
        for(int i=0;i<=b;i++){
            if(l1b) l1b = l1b->next;
        }
        l1a->next = l2;
        while(l2->next) l2=l2->next;
        l2->next = l1b;
        return list1;
    }
};