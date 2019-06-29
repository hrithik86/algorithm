/*adding 2 numbers as linked list
Input:
  First List: 5->6->3  // represents number 563
  Second List: 8->4->2 //  represents number 842
Output
  Resultant list: 1->4->0->5  // represents number 1405      
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

void insertAtBegin(int x,node*&A){
    node*temp=new node();
    temp->data=x;
    temp->link=A;
    A=temp;
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

node*C=NULL;
int add(node*A,node*B){
    node*temp1;node*temp2;
    int len1=len(A),len2=len(B);
    int diff=abs(len1-len2);
    if(A==NULL || B==NULL){
        return 0;
    }
    if(len1>len2){
        while(diff--){
            insertAtBegin(0,B);
        }
    }
    else{
        while(diff--){
            insertAtBegin(0,A);
        }
    }
    temp1=A;
    temp2=B;
    int x=temp1->data;
    int y=temp2->data;
    int sum=sum+x+y;
    int carry=add(A->link,B->link);
    sum=sum+carry;
    carry=sum/10;   
    insert(sum%10,C);
    return carry;
}

int main()
{
    node*A=NULL;node*B=NULL;
    insert(7,A);
    insert(9,A);
    insert(2,A);
    insert(2,A);
    insert(1,B);
    insert(0,B);
    print(A);
    print(B);
    int x=add(A,B);
    if(x!=0){
        insert(x,C);
    }
    Reverse(C);
    print(C);
    return 0;
}
