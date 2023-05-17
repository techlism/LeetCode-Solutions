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
    vector<int> totalnodes(ListNode * head){
        vector<int> nodes;
        while(head){
            nodes.emplace_back(head->val);
            head=head->next;
        }
        return nodes;
    }
public:
    int pairSum(ListNode* head) {
        vector<int>nodes=totalnodes(head);
        int n = nodes.size();
        int ans = INT_MIN;
        for(int i=0;i<n/2;i++){
            int sum = nodes[i] + nodes[n-1-i];
            ans=max(ans,sum);
        }
        return ans;
        
        // Not the most efficient one because of the space complexity O(n).
        // Better approach is  to reverse the second half of the L.L. (floyd cycle detection) and
        // then add and find max.
    }
};