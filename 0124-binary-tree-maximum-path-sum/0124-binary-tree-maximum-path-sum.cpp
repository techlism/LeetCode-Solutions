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
int postorder(TreeNode * root , int &maxSum){
    if(root==nullptr){
        return 0;
    }
    //These Steps are not clear why max has been taken for them.
    int left= max(postorder(root->left,maxSum),0);
    int right=max(postorder(root->right,maxSum),0);
    int currSum = left + right + root->val;
    maxSum=max(maxSum,currSum);
    return root->val + max(left,right);
}
public:
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        postorder(root,maxSum);
        return maxSum;
    }
};