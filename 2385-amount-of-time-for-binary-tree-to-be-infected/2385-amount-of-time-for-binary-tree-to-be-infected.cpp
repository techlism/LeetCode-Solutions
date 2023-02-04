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
    TreeNode * startNode(TreeNode * root,int start,unordered_map<TreeNode*,TreeNode*> &nodeToParent){
        TreeNode * startNode = nullptr;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * front= q.front();
                q.pop();
                if(front->val==start){
                    startNode=front;
                }
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
        return startNode;
    }
    int burnTree(TreeNode * startNode,unordered_map<TreeNode*,TreeNode*> &nodeToParent){
        unordered_map<TreeNode *,bool>visited;
        queue<TreeNode *>q;
        q.push(startNode);
        visited[startNode]=true;
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            bool flag=0;
            for(int i=0;i<size;i++){
                TreeNode * front= q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    flag=1;
                    visited[front->left]=true;
                    q.push(front->left);
                }
                if(front->right && !visited[front->right]){
                    flag=1;
                    visited[front->right]=true;
                    q.push(front->right);
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag=1;
                    visited[nodeToParent[front]]=1;
                    q.push(nodeToParent[front]);
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* startnode = startNode(root,start,nodeToParent);
        return burnTree(startnode,nodeToParent);
    }
};