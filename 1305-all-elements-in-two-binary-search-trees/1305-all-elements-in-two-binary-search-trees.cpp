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
    void pre(TreeNode * root,vector<int>&nodes){
        if(root==nullptr){
            return;
        }
        nodes.push_back(root->val);
        pre(root->left,nodes);
        pre(root->right,nodes);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nodes;
        if(root1==nullptr && root2==nullptr){
            return nodes;
        }
        if(root1){
            pre(root1,nodes);            
        }
        if(root2){
            pre(root2,nodes);    
        }
        sort(nodes.begin(),nodes.end());
        return nodes;
        
        //T.C. 0(NlogN)
        //S.C. 0(N)
    }
};