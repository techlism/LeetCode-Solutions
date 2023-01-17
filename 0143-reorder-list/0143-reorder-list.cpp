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
    void reorderList(ListNode* head) {
        stack<ListNode*>s;
        ListNode* temp=head;
        while(temp!=NULL){
            s.push(temp);
            temp=temp->next;
        }
        int size = (s.size())/2 ;
        temp=head;
        //Inserting top of stack between two Nodes.
        for(int i=0;i<size;i++){
            ListNode * element = s.top();
            s.pop();
            element->next=temp->next;
            temp->next=element;
            temp=temp->next->next;
        }
        temp->next=NULL;        
    }
};