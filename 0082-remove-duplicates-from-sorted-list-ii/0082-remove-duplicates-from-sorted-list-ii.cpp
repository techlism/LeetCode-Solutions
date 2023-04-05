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
    void findDuplicates(ListNode * head , vector<int> & duplicates) {
        if(!head) return;
        while(head && head->next){
            if(head->val==head->next->val){
                duplicates.push_back(head->val);
            }
            head=head->next;
        }
    }   
public:
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> duplicates;
        findDuplicates(head,duplicates);
        ListNode * ans = new ListNode(0);
        ListNode * start = ans;
        while(head){
            if(!binary_search(duplicates.begin(),duplicates.end(),head->val)){
                ListNode * temp = new ListNode(head->val);
                ans->next = temp;
                ans=temp;
            }
            head=head->next;
        }
        return start->next;        
    }
};