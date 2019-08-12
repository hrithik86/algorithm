/*
Print a BT in vertical order
I/P:            1
               / \
              2   3
             / \ / \
            4  5 6  7
                \    \
                 8    9
O/P:
4 
2 
1 5 6 
8 3 
7 
9 
*/

#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int d){
        data=d;
        left=right=NULL;
    }      
};
void printVertical(node*root,int dist,unordered_map<int,vector<int>>&um){
    if(root==NULL) return;
    um[dist].push_back(root->data);
    printVertical(root->left,dist-1,um);
    printVertical(root->right,dist+1,um);
    return;
}
int main()
{
    unordered_map<int,vector<int>>um;    
    node*root=NULL;
    node*temp=new node(1);
    root=temp;
    temp->left=new node(2);
    temp->right=new node(3);
    temp->left->left=new node(4);
    temp->left->right=new node(5);
    temp->left->right->right=new node(8);
    temp->right->left=new node(6);
    temp->right->right=new node(7);
    temp->right->right->right=new node(9);
    printVertical(root,0,um);
    int min_key=-2;
    int max_key=3;
    for (int key = min_key; key<=max_key; key++) 
        { 
            for(int i=0;i<um[key].size();i++){
                cout<<um[key][i]<<" ";
            }
            cout<<endl;
        } 
    return 0;
}
