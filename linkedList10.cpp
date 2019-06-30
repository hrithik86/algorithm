/*sort a linked list of 0s,1s and 2s
Given a linked list of 0s, 1s and 2s, sort it.
Following steps can be used to sort the given linked list.
1) Traverse the list and count the number of 0s, 1s and 2s. Let the counts be n1, n2 and n3 respectively.
2) Traverse the list again, fill the first n1 nodes with 0, then n2 nodes with 1 and finally n3 nodes with 2.
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

void sortLL(node*&A){
    node*temp=A;int c[3]={0};
    while(temp!=NULL){
        c[temp->data]++;
        temp=temp->link;
    }
    temp=A;int i=0;
    while (temp != NULL)  
    {  
        if(c[i] == 0)  
            i++;  
        else
        {   
            temp->data = i;  
            c[i]--;
            temp = temp->link; 
        }  
    }
    return;
}

int main()
{
    node*A=NULL;
    insert(2,A);
    insert(1,A);
    insert(0,A);
    insert(1,A);
    insert(0,A);
    insert(2,A);
    insert(0,A);
    insert(2,A);
    print(A);
    sortLL(A);
    print(A);
    return 0;
}
