// Largest Independent Set Problem in binary tree
// https://www.geeksforgeeks.org/largest-independent-set-problem-dp-26/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    int lis;    
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

// Recursive
int findLargestSet(Node*root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    int inc=1,exc=0;
    // include the current node
    if(root->left) inc+=findLargestSet(root->left->left)+findLargestSet(root->left->right);
    if(root->right) inc+=findLargestSet(root->right->left)+findLargestSet(root->right->right);
    // don't include the current node
    exc+=findLargestSet(root->left)+findLargestSet(root->right);
    return max(inc,exc);
}

// Memoized
int findLargestSetDP(Node*root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) {
        root->lis=1;
        return root->lis;
    }
    if(root->lis) return root->lis;
    int inc=1,exc=0;
    // include the current node
    if(root->left) inc+=findLargestSetDP(root->left->left)+findLargestSetDP(root->left->right);
    if(root->right) inc+=findLargestSetDP(root->right->left)+findLargestSetDP(root->right->right);
    // don't include the current node
    exc+=findLargestSetDP(root->left)+findLargestSetDP(root->right);
    root->lis=max(inc,exc);
    return root->lis;
}

int main() {
    Node *root = new Node(20); 
    root->left = new Node(8); 
    root->left->left = new Node(4); 
    root->left->right = new Node(12); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 
    root->right = new Node(22); 
    root->right->right = new Node(25);
    //cout<<findLargestSet(root);
    cout<<findLargestSetDP(root);
}
