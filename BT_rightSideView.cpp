/******************************************************************************
Binary Tree Right Side View - Leetcode

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

*******************************************************************************/
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
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>v;
        if(root==NULL) return v;
        v.push_back(root->val);
        q.push(root);
        TreeNode*t=NULL;
        q.push(t);
        while(q.size()>1){
            TreeNode*temp=q.front();
            q.pop();
            if(temp==NULL && q.size()>=1){
                v.push_back(q.front()->val);
                q.push(t);
                continue;
            }
            if(temp->right!=NULL) q.push(temp->right);
            if(temp->left!=NULL) q.push(temp->left);
        }
        return v;
    }
};