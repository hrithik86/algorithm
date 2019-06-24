//Intersection Point of 2 linked list
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

void poi(node*A,node*B){
    int len1=len(A),len2=len(B),diff;
    // node*temp1=A;node*temp2=B;
    
    if(len1>len2){
        diff=len1-len2;
        int x=diff;
        while(x--){
            A=A->link;
        }
    }
    else{
        diff=len2-len1;
        int x=diff;
        while(x--){
            B=B->link;
        }
    }
    while(A!=NULL || B!=NULL){
        if(A==B){
            cout<<"Point of Intersection:"<<A->data<<endl;
            break;
        }
        A=A->link;
        B=B->link;
    }
    
}

int main()
{
    node*A=NULL,*B=NULL;
    node*temp=new node(); node*temp1=new node();
    A=temp;B=temp1;
    
    temp->data=3;
    temp1->data=10;

    temp=new node();
    temp->data=6;
    A->link=temp;
    
    temp=new node();
    temp->data=9;
    A->link->link=temp;

    temp=new node();
    temp->data=15;
    A->link->link->link=temp;
    B->link=temp;

    temp=new node();
    temp->data=30;
    A->link->link->link->link=temp;
    B->link->link=temp;
    temp->link=NULL;
    
    print(A);
    print(B);
    
    /*to make sure that we have successfully intersected the 2 linked list,
    //we can change the print function to display the address of the nodes. 
    If we have it correctly, the address of and after their point of intersection will be same. */
    
    poi(A,B);           //point of intersection of 2 linked list
    return 0;
}
