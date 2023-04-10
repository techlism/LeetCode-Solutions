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
    int totalNodes(ListNode * head){
        int count = 0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int total = totalNodes(head);
        ListNode * temp = head;
        ListNode * first = nullptr;
        ListNode * second = nullptr;
        for(int i=1;i<=total;i++){
            if(i==k) first = temp;
            if(i==total-k+1) second = temp;
            temp=temp->next;
        }
        swap(first->val,second->val);
        return head;
    }
};