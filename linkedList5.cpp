//Deleting alternate nodes from linked list
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

int len(node* A){
    int length=0;
    while(A!=NULL){
        A=A->link;
        length++;
    }
    return length;
}

void deleteAlternate(node*&A){
    node*temp=A;
    while(temp!=NULL && temp->link!=NULL){
        node*temp1=temp->link;
        temp->link=temp1->link;
        temp=temp1->link;
        delete temp1;
    }
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
    print(A);
    deleteAlternate(A);
    print(A);
    return 0;
}
