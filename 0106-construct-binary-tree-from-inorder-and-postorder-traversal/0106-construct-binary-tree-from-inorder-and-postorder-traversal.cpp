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
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int &rootIndex, int start, int end, unordered_map<int,int> &nodeToIndex) {
        if(start > end || rootIndex < 0) {
            return nullptr;            
        }
        int pivot = nodeToIndex[postorder[rootIndex--]];
        TreeNode* root = new TreeNode(inorder[pivot]); 
        root->right = build(postorder, inorder, rootIndex, pivot+1, end, nodeToIndex);
        root->left = build(postorder, inorder, rootIndex, start, pivot-1, nodeToIndex);      
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIndex = postorder.size()-1;
        unordered_map<int,int> nodeToIndex;
        for (int i=0; i< inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
        return build(postorder, inorder, rootIndex, 0,inorder.size()-1,nodeToIndex);
    }

};