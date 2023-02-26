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
    void create(ListNode * & tail1 , int val , ListNode * &head1){
        ListNode * node = new ListNode(val);
        if(tail1==nullptr && head1==nullptr){
            tail1=node;
            head1=tail1;
            return;
        }
        else{
            tail1->next=node;
            tail1=node;
            return;
        }
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return head;
        }
        ListNode * tail1=nullptr;
        ListNode * head1=nullptr;
        while(head){
            if(head->val!=val){
               create(tail1,head->val,head1); 
            }
            head=head->next;
        }
        return head1;
        //Time Complexity - O(N);
        //Space Complexity - O(N);
        //Can be optimized.
    }
};