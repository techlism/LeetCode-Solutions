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
private:
    int getlength(ListNode* head){
        int length=0;
        //traverse the linkedlist
        while(head!=NULL){
            head=head->next;
            length++;
        }
        return length;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int count=0;
        int length=getlength(head)/2;
        while(count<length){
            head=head->next;
            count++;
        }
        return head;
    }
};