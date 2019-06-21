//Following operations are done on the linked list:
    //insertion at nth place
    //insertion at beginning
    //insertion at end
    //deletion at nth place
    //printing
    //printing in forward and reverse order using recursion
    //reversing the linked list: Iterative method and By recursion
    

#include <iostream>
using namespace std;

struct node{
    int data;
    node* link;
};

node* A=NULL;

void print(){
    node* temp1=new node();
    temp1=A;
    cout<<"List is ";
    while(temp1!=NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->link;
    }
    cout<<endl;
    return;
}

//=============================== printing by recursion=======================================

void printForward(node* temp){
    if(temp==NULL){
        return;
    }
    cout<<temp->data<<" ";
    temp=temp->link;
    printForward(temp);
}

void printReverse(node* temp){
    
    if(temp==NULL){
        
        return;
    }
    printReverse(temp->link);
    cout<<temp->data<<" ";
    
}
//============================================================================================

void insert(int x){
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

void del(int n){
    node* temp1=new node();
    temp1=A;
    if(n==1){
        A=temp1->link;
        delete temp1;
        return;
    }
    int i=1;
    while(i<n-1){
        temp1=temp1->link;
        i++;
    }
    node* temp2=temp1->link;
    temp1->link=temp2->link;
    delete (temp2);
    return;
}

void insertNth(int n,int x){
    node* temp=new node();node*temp1=new node();
    temp1=A;
    temp->data=x;
    if(n==1){
        temp->link=temp1;
        A=temp;
        return;
    }
    int i=1;
    while(i<n-1){
        temp1=temp1->link;
        i++;
    }
    temp->link=temp1->link;
    temp1->link=temp;
    return;
}

void ReverseRecursion(node *temp){
    if(temp->link==NULL){
        A=temp;
        return;
    }
    ReverseRecursion(temp->link);
    node* q;
    q=temp->link;
    q->link=temp;
    temp->link=NULL;
}

void Reverse(){
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

int main()
{   
    insert(2);
    insert(3);
    insert(7);
    insert(5);
    insert(9);
    print();
    del(3);             //deletion at nth position
    print();
    insert(10);
    print();
    insertNth(3,6);
    print();
    node* temp=A;
    printForward(temp);
    cout<<endl;
    printReverse(temp);
    cout<<endl;
    print();
    Reverse();
    print();
    temp=A;
    ReverseRecursion(temp);
    print();
    return 0;
}
