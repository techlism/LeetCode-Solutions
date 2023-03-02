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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode *makeBST(ListNode *head, ListNode *tail){
    	if( head == tail ){
    		return nullptr;            
        }

    	if( head->next == tail ){	
    		TreeNode *root = new TreeNode( head->val );
    		return root;
    	}
    	
        ListNode *mid = head, *temp = head;
        //Floyd Cycle detection (something like that)
        //Temp will go till tail while mid will stop at mid-node
    	while( temp != tail && temp->next != tail ) {
    		mid = mid->next;
    		temp = temp->next->next;
    	}
        //Create a new node and that will be the mid val.
    	TreeNode *root = new TreeNode( mid->val);
    	
        root->left = makeBST(head, mid);
    	root->right = makeBST(mid->next,tail);
    	
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return makeBST(head,nullptr);
    }
};