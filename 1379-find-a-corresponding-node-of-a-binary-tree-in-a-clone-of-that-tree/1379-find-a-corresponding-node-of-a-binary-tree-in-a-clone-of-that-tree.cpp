/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    void findNode(TreeNode *  cloned, TreeNode* &target){
        if(cloned==nullptr){
            return;
        }
        findNode(cloned->left,target);
        if(cloned->val==target->val){
            target=cloned;
        }
        findNode(cloned->right,target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target){
      findNode(cloned,target);
        return target;
    }
};