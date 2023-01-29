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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIndex, int start, int end, unordered_map<int,int> &nodeToIndex) {
        if(start > end) 
            return nullptr;
        
        int pivot = nodeToIndex[preorder[rootIndex++]];
        TreeNode* node = new TreeNode(inorder[pivot]); 
        
        node->left = build(preorder, inorder, rootIndex, start, pivot-1, nodeToIndex);
        node->right = build(preorder, inorder, rootIndex, pivot+1, end, nodeToIndex);
             
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIndex = 0;
        unordered_map<int,int> nodeToIndex;
        for (int i=0; i< inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
        return build(preorder, inorder, rootIndex, 0, inorder.size()-1, nodeToIndex);
    }

};