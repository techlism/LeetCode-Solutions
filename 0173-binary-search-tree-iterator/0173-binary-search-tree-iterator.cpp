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
class BSTIterator {
private:
    vector<int> inorderVal;
    int i=0;
    TreeNode * node ;
    void inorder(TreeNode *node){
        if(node==nullptr){
            return;
        }
        inorder(node->left);
        inorderVal.push_back(node->val);
        inorder(node->right);
}
public:
    BSTIterator(TreeNode* root) {
        node=root;
        inorder(node);
    }
    
    int next() {
        return inorderVal[i++];
    }
    
    bool hasNext() {
        if(i<inorderVal.size()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */