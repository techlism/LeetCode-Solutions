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
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) 
            return -1;
        int level = 0, maxLevel = -1, maxSum = INT_MIN;
        
        queue<TreeNode*> q; 
        q.push(root); 
        while (!q.empty()) {
            level++;
            int n = q.size(), sum = 0; 
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val; 
                if (cur->left) 
                    q.push(cur->left);
                if (cur->right) 
                    q.push(cur->right); 
            }
            if (sum > maxSum) {
                maxLevel = level; 
                maxSum = sum;
            }
        }
        return maxLevel;        
    }
};