/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getLen(ListNode * head){
        int count = 0;
        while(head){
            count += 1;
            head = head -> next;
        }
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getLen(headA);
        int len2 = getLen(headB);
        if(len1 > len2){
            while(len1 != len2){
                headA = headA -> next;
                len1 --;
            }
        }
        else{
            while(len1 != len2){
                headB = headB -> next;
                len2 --;
            }        
        }
        while(headA && headB){
            if(headA == headB) return headA;
            else{
                headA = headA -> next;
                headB = headB -> next;
            }
        }
        return nullptr;
    }   
};