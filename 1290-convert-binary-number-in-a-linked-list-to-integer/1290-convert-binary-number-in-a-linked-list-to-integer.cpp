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
    int getlength(ListNode * head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
public:
    int getDecimalValue(ListNode* head) {
        int length=getlength(head);
        int ans=0;
        for(int i=0;i<length;i++){
            int bit = head -> val;
            ans=ans+(bit * pow(2,length-1-i));
            head=head->next;
        }
        return ans;
    }
};