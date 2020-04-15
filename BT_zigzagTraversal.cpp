/*
Level order traversal in spiral form

Complete the function to print spiral order traversal of a tree.
Input:
2
1 3 2  
10 20 30 40 60 
Output:
1 3 2
10 20 30 60 40 

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, the spiral level order would be 1 3 2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the spiral level order would be 10 20 30 60 40
*/
void printSpiral(Node *root)
{
    if(root==NULL) return;
    int i=1;
    deque<Node*>q1;
    deque<Node*>q2;
    q1.push_front(root);
    while(!q1.empty()){
        int S=q1.size();
        if(i&1){
            for(int i=0;i<S;i++){
                Node*temp=q1.front();
                q1.pop_front();   
                cout<<temp->data<<" ";
                if(temp->right!=NULL) q2.push_front(temp->right);
                if(temp->left!=NULL) q2.push_front(temp->left);
            }
        }
        else{
            for(int i=0;i<S;i++){
                Node*temp=q1.front();
                q1.pop_front();   
                cout<<temp->data<<" ";
                if(temp->left!=NULL) q2.push_front(temp->left);
                if(temp->right!=NULL) q2.push_front(temp->right);
            }
        }
        q1.swap(q2);
        i=abs(i-1);
    }
    return;
}
