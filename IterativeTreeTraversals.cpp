// Iterative tree traversals (Preorder, Inorder, Postorder) using stack
// Reference: Pepcoding

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void treeTraversal(TreeNode* root) {
    vector<int>preorder;
    vector<int>inorder;
    vector<int>postorder;
    stack<pair<TreeNode*,int>>s;
    s.push({root,1});
    while(!s.empty()){
        pair<TreeNode*,int>t=s.top();
        if(t.first==NULL){
            s.pop();
            continue;
        }
        if(t.second==1){
            preorder.push_back(t.first->val);
            s.top().second=2;
            s.push({t.first->left,1});
        }
        else if(t.second==2){
            inorder.push_back(t.first->val);
            s.top().second=3;
            s.push({t.first->right,1});
        }
        else{
            postorder.push_back(t.first->val);
            s.pop();
        }
    }
    cout<<"Preorder: ";
    for(int i=0;i<preorder.size();i++) cout<<preorder[i]<<" "; 
    cout<<"\nInorder: ";
    for(int i=0;i<inorder.size();i++) cout<<inorder[i]<<" ";
    cout<<"\nPostorder: ";
    for(int i=0;i<postorder.size();i++) cout<<postorder[i]<<" ";
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    /*
            1
             \
              2
             /
            3
    */

    treeTraversal(root);
}
