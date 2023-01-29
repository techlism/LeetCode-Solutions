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
    void countPaths(TreeNode* root,int targetSum,vector<int>path,int &count){
        if(root==nullptr){
            return;
        }
        path.push_back(root->val);
        countPaths(root->left,targetSum,path,count);
        countPaths(root->right,targetSum,path,count);
        int size=path.size();
        size_t sum=0;
        for(int i=size-1;i>=0;i--){
            sum=sum+path[i];
            if(sum==targetSum){
                count++;
            }
        }
        path.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        vector<int>path;
        countPaths(root,targetSum,path,count);
        return count;
    }
};