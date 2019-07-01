/*Cycle detection and finding first node of the loop(Floyd's Cycle) */
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

int checkCycle(node*A){
    node*slow=A->link;
    node*fast=A->link->link;
    while(slow && fast && fast->link){
        if(fast==slow){
            slow=A;
            while(slow!=fast){      //loop to find the starting node
                slow=slow->link;
                fast=fast->link;
            }
            cout<<slow->data<<endl;
            return 1;
        }
        fast=fast->link->link;
        slow=slow->link;
    }
    return 0;
}
int main()
{   node*A=NULL;
    insert(7,A);
    insert(9,A);
    insert(2,A);
    insert(4,A);
    insert(6,A);
    insert(10,A);
    //============================making a loop====================================
    //connecting the last node to the second node in the linked list to make a loop
    node*temp=A;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    node*temp1=A->link;
    temp->link=temp1;
    //=============================================================================
    if(checkCycle(A)){
        cout<<"loop found"<<endl;
    }
    else    cout<<"no loop found"<<endl;
    return 0;
}
