// Binary Tree from string expression: Submission on LintCode
// https://www.lintcode.com/problem/construct-binary-tree-from-string/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(TreeNode*root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

TreeNode* formTree(string s, int low,int high){
    if(low>=high) return NULL;
    low++;high--;
    TreeNode*root;
    bool negative=false;
    if(s[low]=='-') {
        low++;
        negative=true;
    }
    int num=0;
    while(s[low]!='(' && low<=high){
        num=(num*10)+(s[low]-'0');
        low++;
    }
    if(negative) num*=(-1);
    root=new TreeNode(num);
    int i,open=0,close=0;
    for(i=low;i<=high;i++){
        if(s[i]=='(') open++;
        if(s[i]==')') close++;
        if((open-close)==0){
            break;
        }
    }
    root->left=formTree(s,low,i);
    root->right=formTree(s,i+1,high);
    return root;
}

void constructTree(string str){
    string s="("+str+")";
    TreeNode*root=formTree(s,0,s.size()-1);
    preorder(root);
}  
 
int main() {
    string str="1(2(3(4(5(6(7(8)))))))(9(10(11(12(13(14(15)))))))";
    constructTree(str);
}
