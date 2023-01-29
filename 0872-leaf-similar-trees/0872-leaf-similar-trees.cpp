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
    void post1(TreeNode * root1,vector<int> & leaf1){
        if(root1==nullptr){
            return;
        }
        post1(root1->left,leaf1);
        post1(root1->right,leaf1);
        if(root1->left==nullptr && root1->right==nullptr){
            leaf1.push_back(root1->val);
        }
    }
    void post2(TreeNode * root2,vector<int> & leaf2){
        if(root2==nullptr){
            return;
        }
        post2(root2->left,leaf2);
        post2(root2->right,leaf2);
        if(root2->left==nullptr && root2->right==nullptr){
            leaf2.push_back(root2->val);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf1;
        vector<int>leaf2;
        post1(root1,leaf1);
        post2(root2,leaf2);
        if(leaf1.size()!=leaf2.size()){
            return false;
        }
        for(int i=0;i<leaf1.size();i++){
            if(leaf1[i]!=leaf2[i]){
                return false;
            }
        }
        
        return true;
        
    }
};