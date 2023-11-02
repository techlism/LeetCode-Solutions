class Solution {
private:
    void inorder(vector<TreeNode *> & nodes, TreeNode * root){
        if(!root) return;
        inorder(nodes,root->left);
        nodes.push_back(root);
        inorder(nodes,root->right);
    }
    void inorderVal(TreeNode * root,pair<int,int> &p){
        if(!root) return;
        inorderVal(root->left,p);
        p.first+=root->val;
        p.second+=1;
        inorderVal(root->right,p);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        vector<TreeNode *> nodes;
        inorder(nodes,root);
        unordered_map<TreeNode*,int>nodeAvg;
        for(auto node : nodes){
            pair<int,int> p = {0,0};
            inorderVal(node,p);
            nodeAvg[node] = p.first/p.second;
        }
        int ans=0;
        for(auto node : nodeAvg){
            if(node.first->val==node.second) ans+=1;
        }
        return ans;
    }
};