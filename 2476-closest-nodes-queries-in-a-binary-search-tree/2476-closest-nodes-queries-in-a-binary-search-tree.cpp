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
    void inorder(TreeNode * root, vector<int> & values){
        if(root==nullptr){
            return;
        }
        inorder(root->left,values);
        values.push_back(root->val);
        inorder(root->right,values);
    }
    
    pair<int,int> greaterSmaller(vector<int>&values,int n){
        pair<int,int> ans=make_pair(-1,-1);
        int s=0;
        int e=values.size()-1;
        int mid = (s+e)/2;
        while(s<=e){
            if(values[mid] <= n){
                ans.first=mid;
            }
            if(values[mid] >= n){
                ans.second=mid;
            }
            if(values[mid]<n){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
    
    int binarySearch(vector<int>&values,int n){
        int s=0;
        int e=values.size()-1;
        int mid = (s+e)/2;
        while(s<=e){
            if(values[mid]==n){
                return mid;
            }
            if(values[mid]<n){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return -1;
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> values;
        inorder(root,values);
        vector<vector<int>>ans;
        for(int i=0;i<queries.size();i++){
            vector<int>response;
            if(binarySearch(values,queries[i]) == -1){
                pair<int,int>p=greaterSmaller(values,queries[i]);
                if(p.first!=-1){
                    response.push_back(values[p.first]);
                }
                else{
                    response.push_back(-1);
                }
                if(p.second!=-1){
                    response.push_back(values[p.second]);
                }
                else{
                    response.push_back(-1);
                }                
            }
            else{
                int index=binarySearch(values,queries[i]);
                response.push_back(values[index]);
                response.push_back(values[index]);
            }
            ans.push_back(response);
        }
        return ans;
    }
};