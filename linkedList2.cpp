//Following operations are done on the linked list:
    //length of the linked list
    //finding element recursively
    //midpoint of the linked list
    //implement bubble sort

#include <iostream>
using namespace std;

struct node{
    int data;
    node* link;
};

void print(node* A){
    cout<<"List is ";
    while(A!=NULL){
        cout<<A->data<<" ";
        A=A->link;
    }
    cout<<endl;
    return;
}

void insert(int x,node*&A){
    node* temp=new node();node* temp1=new node();
    temp1=A;
    temp->data=x;
    temp->link=NULL;
    if(A==NULL){        //empty list
        A=temp;
    }
    else{               //list is not empty 
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

int pos=0;
void findElement(int x,node*A){
    pos++;
    if(A==NULL){
        return;
    }
    if(x==A->data){
        cout<<"Element found at position:"<<pos<<endl;
        return;
    }
    else{
        findElement(x,A->link);    
    }

    
}


void findmidPoint(node*A){
    node*slow=A;
    node*fast=A->link;
    while(fast&&fast->link){
        fast=fast->link->link;
        slow=slow->link;
    }
    cout<<"Midpoint: "<<slow->data<<endl;
}

void bubbleSort(node*&A){
    int n=len(A);
    for(int i=0;i<n-1;i++){
        //pairwise swapping
        node* current=A;
        node* prev=NULL;
        while(current!=NULL&&current->link!=NULL){
            if(current->data>current->link->data){
                //swapping
                if(prev==NULL){
                    node*next=current->link;
                    current->link=next->link;
                    next->link=current;
                    A=next;
                    prev=next;
                }
                else{
                    //middle
                    node*next=current->link;
                    current->link=next->link;
                    next->link=current;
                    prev->link=next;
                    prev=next;
                }
            }
            else{
                prev=current;
                current=current->next;
            }
        }
        
        
    }
}

int main()
{   
    node*A=NULL;
    insert(3,A);
    insert(2,A);
    insert(7,A);
    insert(5,A);
    insert(1,A);
    print(A);
    int length=len(A);
    cout<<"Length of the linked list is: "<<length<<endl;
    findElement(2,A);
    findmidPoint(A);
    print(A);
    bubbleSort(A);
    print(A);
    return 0;
}
