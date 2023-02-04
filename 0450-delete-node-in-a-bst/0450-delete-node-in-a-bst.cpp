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
    int minval(TreeNode * root){
        while(root->left!=nullptr){
            root=root->left;
        }
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return root;
        }
        if(root->val==key){
            //leaf Node
            if(root->left==nullptr && root->right==nullptr){
                return nullptr;
            }
            //1 child
            if(root->left!=nullptr && root->right==nullptr){
                return root->left;
            }
            if(root->left==nullptr && root->right!=nullptr){
                return root->right;
            }
            //2 children
            if(root->left!=nullptr && root->right!=nullptr){
                int min=minval(root->right);
                root->val=min;
                root->right=deleteNode(root->right,min);
                return root;
            }
        }
        else if(root->val > key){
            root->left=deleteNode(root->left,key);
            return root;
        }
            root->right=deleteNode(root->right,key);
            return root;
    }
};