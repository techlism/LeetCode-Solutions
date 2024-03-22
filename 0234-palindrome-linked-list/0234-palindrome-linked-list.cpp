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
    bool isPalindrome(ListNode* head) {
        std::queue<int> queue;

        auto current_node = head;
        ListNode *prev_node = nullptr;
        while (current_node) {
            queue.push(current_node->val);
            ListNode *next_node = current_node->next;
            current_node->next = prev_node;
            prev_node = current_node;
            current_node = next_node;
        }
        head = prev_node;

        while (head) {
            if (queue.front() != head->val) {
                return false;
            }
            head = head->next;
            queue.pop();
        }

        return queue.empty();
    }
};