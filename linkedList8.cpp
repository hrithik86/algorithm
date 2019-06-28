/*k reverse
Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
Output:  3->2->1->6->5->4->8->7->NULL. 

Inputs:   1->2->3->4->5->6->7->8->NULL and k = 5
Output:  5->4->3->2->1->8->7->6->NULL.
*/
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* link;
};

void print(node*A){
    cout<<"Linked list is: ";
    while(A!=NULL){
        cout<<A->data<<" ";
        A=A->link;
    }
    cout<<endl;
}

void insert(int x,node*&A){
    node*temp=new node();node*temp1=new node();
    temp1=A;
    temp->data=x;
    temp->link=NULL;
    if(A==NULL){
        A=temp;
    }
    else{
        while(temp1->link!=NULL){
            temp1=temp1->link;
        }
        temp1->link=temp;
    }
    return;
}



node* kReverse(node*&A,int k){
    node* current,*next,*prev;
    current=A;
    prev=NULL;
    next=NULL;
    int count =0;
    /*reverse first k nodes of the linked list */
    while(current!=NULL && count <k){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
        count++;
    }
     /* next is now a pointer to (k+1)th node  
    Recursively call for the list starting from current.  
    And make rest of the list as next of first node */
    if(next!=NULL){
        A->link=kReverse(next,k);    
    }
    /* prev is new head of the input list */
    return prev;
}

int len(node* A){
    int length=0;
    while(A!=NULL){
        A=A->link;
        length++;
    }
    return length;
}

int main()
{
    node*A=NULL;
    insert(1,A);
    insert(2,A);
    insert(3,A);
    insert(4,A);
    insert(5,A);
    insert(6,A);
    insert(7,A);
    insert(8,A);
    print(A);
    A=kReverse(A,3);
    print(A);
    return 0;
}
