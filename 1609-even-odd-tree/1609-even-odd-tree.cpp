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
    bool isEvenOddTree(TreeNode* root) {
        if(root->val % 2 ==0){
            return false;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size=q.size();
            vector<int>levels;
            for(int i=0;i<size;i++){
                TreeNode * front =q.front();
                q.pop();
                levels.push_back(front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            if(level%2==0){
            if(levels.size()==1 && levels[0] % 2 == 0){
                return false;
            }
            for(int i=0;i<levels.size()-1;i++){
                if(levels[i]>levels[i+1] || levels[i]%2==0 ||levels[i+1]%2==0 || levels[i]==levels[i+1]){
                    return false;
                }
            }                
            }
            else{
            if(levels.size()==1 && levels[0] % 2 != 0){
                return false;
            }            
            for(int i=0;i<levels.size()-1;i++){
                if(levels[i]<levels[i+1] || levels[i]%2!=0 ||levels[i+1]%2!=0 || levels[i]==levels[i+1]){
                    return false;
                }
            }                
            }
            level++;
        }
        return  true;
    }
};