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
// class Solution {
// private:  
//     void findDuplicates(ListNode * head , vector<int> & duplicates) {
//         if(!head) return;
//         while(head && head->next){
//             if(head->val==head->next->val){
//                 duplicates.push_back(head->val);
//             }
//             head=head->next;
//         }
//     }   
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         vector<int> duplicates;
//         findDuplicates(head,duplicates);
//         ListNode * ans = new ListNode(0);
//         ListNode * start = ans;
//         while(head){
//             if(!binary_search(duplicates.begin(),duplicates.end(),head->val)){
//                 ListNode * temp = new ListNode(head->val);
//                 ans->next = temp;
//                 ans=temp;
//             }
//             head=head->next;
//         }
//         return start->next;        
//     }
// };
// ⤴️ 1st approach
// \U0001f447⤵️ Second approach
class Solution {
private:
    void insertList(ListNode * & ans , int val){
        ListNode * temp = new ListNode(val);
        if(!ans){
            ans = temp;
            return;
        }
        temp->next = ans;
        ans = temp;
        return;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * curr = head;
        stack<int>s;
        int prev=0;
        while(curr){
            if(!s.empty() && s.top()==curr->val && curr){
                while(s.top()==curr->val){
                    curr=curr->next;
                    if(!curr) break;
                }
                s.pop();
            }
            else{
                s.push(curr->val);
                curr=curr->next;
            }
        }
        ListNode * ans = nullptr;
        while(!s.empty()){
            insertList(ans,s.top());
            s.pop();
        }
        return ans;
    }
};