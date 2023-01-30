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
    pair<int,int> maxandpos(int start,int end,vector<int> &nums,unordered_map<int,int>&valtopos){
        pair<int,int> ans=make_pair(INT_MIN,0);
        for(int i=start;i<=end;i++){
            ans.first=max(ans.first,nums[i]);
        }
        ans.second=valtopos[ans.first];
        return ans;
    }
    TreeNode * maxTree(int start,int end,vector<int> &nums,unordered_map<int,int>&valtopos){
        if(start>end){
            return nullptr;
        }
        pair<int,int>mp=maxandpos(start,end,nums,valtopos);
        int position=mp.second;
        int element =mp.first;
        TreeNode * root = new TreeNode(element);
        root->left=maxTree(start,position-1,nums,valtopos);
        root->right=maxTree(position+1,end,nums,valtopos);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        unordered_map<int,int>valtopos;
        for(int i=0;i<nums.size();i++){
            valtopos[nums[i]]=i;
        }
        int end=nums.size()-1;
        return maxTree(0,end,nums,valtopos);
    }
};