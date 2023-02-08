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
    TreeNode * buildtree(int s,int e ,vector<int>&nums){
        if(s>e){
            return nullptr;
        }
        int mid = (s+e)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left=buildtree(s,mid-1,nums);
        root->right=buildtree(mid+1,e,nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildtree(0,nums.size()-1,nums);
    }
};