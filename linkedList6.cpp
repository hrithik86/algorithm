//Whether a linked list is palindrome or not
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

void palindrome(node*A){
    node* mid=findmidPoint(A);
    node*B=NULL;
    B=mid->link;
    mid->link=NULL;
    Reverse(B);
    int flag=1;
    while(A!=NULL && B!=NULL){
        if(A->data != B->data){
            cout<<"not palindrome"<<endl;
            flag=0;
            break;
        }
        A=A->link;
        B=B->link;
    }
    if(flag==1) cout<<"palindrome"<<endl;
    return;
}

int main()
{
    node*A=NULL;
    insert(1,A);
    insert(2,A);
    insert(3,A);
    insert(3,A);
    insert(2,A);
    insert(1,A);
    print(A);
    palindrome(A);
    return 0;
}
