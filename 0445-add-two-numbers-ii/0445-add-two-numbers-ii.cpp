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
    void reverse(ListNode * & head){
        ListNode * curr = head;
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    void insertHead(int num,ListNode * & ans){
        ListNode * nodetoInsert = new  ListNode(num);
        if(ans==nullptr){
            ans = nodetoInsert;
            return;
        }
        else{
            nodetoInsert->next=ans;
            ans=nodetoInsert;
            return;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverse(l1);
        reverse(l2);
        ListNode * ans = nullptr;
        int carry=0;
        while(l1 || l2){
            if(l1 && l2){
                int num = l1->val + l2->val + carry;
                carry=num/10;
                insertHead((num%10),ans);
                l1=l1->next;
                l2=l2->next;
            }
            if(l1 && !l2){
                int num = l1->val + carry;
                carry=num/10;
                insertHead((num%10),ans);
                l1=l1->next;
            }
            if(!l1 && l2){
                int num = l2->val + carry;
                carry=num/10;
                insertHead((num%10),ans);
                l2=l2->next;
            }
        }
        
        if(carry){
            insertHead(carry,ans);
        }
        return ans;
    }
};