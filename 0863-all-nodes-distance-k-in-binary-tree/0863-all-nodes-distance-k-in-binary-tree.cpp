/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void createMap(TreeNode * root,unordered_map<TreeNode*,TreeNode*> &nodeToParent){
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * front= q.front();
                q.pop();
                if(front->left){
                    nodeToParent[front->left]=front;
                    q.push(front->left);
                }
                if(front->right){
                    nodeToParent[front->right]=front;
                    q.push(front->right);
                }                
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> nodeToParent;
        createMap(root,nodeToParent);
        unordered_map<TreeNode *,bool>visited;
        queue<TreeNode *>q;
        q.push(target);
        visited[target]=true;
        vector<int>ans;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            if(level++==k){
                break;
            }
            for(int i=0;i<size;i++){
                TreeNode * front= q.front();
                q.pop();
                if(front->left && !visited[front->left]){             
                    visited[front->left]=true;
                    q.push(front->left);
                }
                if(front->right && !visited[front->right]){        
                    visited[front->right]=true;
                    q.push(front->right);
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    visited[nodeToParent[front]]=true;
                    q.push(nodeToParent[front]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};