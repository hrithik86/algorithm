/*Alternate merging of nodes in a linked list
ex.
I/P:    L1->L2->L3->L4->L5->L6
O/P:    L1->L6->L2->L5->L3->L4
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



void Reverse(node*&A){
    node* current,*next,*prev;
    current=A;
    prev=NULL;
    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    A=prev;
}

int len(node* A){
    int length=0;
    while(A!=NULL){
        A=A->link;
        length++;
    }
    return length;
}

node* findmidPoint(node*A){
    node*slow=A;
    node*fast=A->link;
    while(fast&&fast->link){
        fast=fast->link->link;
        slow=slow->link;
    }
    return slow;
}

void altmerge(node*A){
    const int l=len(A);
    node*mid=findmidPoint(A);
    node*B=mid->link;
    mid->link=NULL;
    Reverse(B);
    int i=0;
    node*C=A;node*temp=C;
    while(i<l-1){
        if(i&1){
            B=B->link;
            temp->link=A;
            temp=temp->link;
        }
        else{
            A=A->link;
            temp->link=B;
            temp=temp->link;
        }
        i++;
    }
    print(C);
    return;
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
    // insert(7,A);
    print(A);
    altmerge(A);
    return 0;
}
