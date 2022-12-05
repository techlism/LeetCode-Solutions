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
    int getTotal(ListNode* head){
        if(head==NULL){
            return 0;
        }
        if(head->next==NULL){
            return 1;
        }
        int count=-1;
        while(head->next!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int total=getTotal(head);
        int mid=total/2;
        int count=0;
        ListNode * temp=head;
        while(count<mid && temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        ListNode* nodeToDelete= temp->next;
        temp->next=temp->next->next;
        delete(nodeToDelete);
        return head;
        
    }
};