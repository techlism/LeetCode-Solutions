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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }

    ListNode* getMid(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeSort(ListNode* &head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* midNext = mid->next;
        mid->next = nullptr;
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(midNext);
        return merge(left, right);
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Approach : merge the lists then sort them using merge sort for linkedlists
        ListNode * merged = new ListNode(-1);
        ListNode * temp = merged;
        for(auto list : lists){
            while(list){
                temp->next = list;
                temp=list;
                list=list->next;
            }
        }
        return mergeSort(merged->next);
        //Time Complexity : O(NlogN) - Because of merge sort
        // Space Complexity: O(N*K) - Because of creation of a new list.
        // It could be optimised very easily by just taking two lists from lists vector and then merge them to get a new list till we have a just a single list.
        
    }
};
