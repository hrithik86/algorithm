//various operations are performed on the linked list:
    //1.finding kth element from end without calculating the length of the linked list
    //2.given 2 sorted linked lists merging them into a sorted linked list
    //3.implementing merge sort

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* link;
    ~node(){
        cout<<"Deleting node "<<data<<endl;
        if(link!=NULL){
            delete link;        //delete is calling the destructor of the next one
        }
    }
};

void print(node*A){
    cout<<"Linked list is: ";
    while(A!=NULL){
        cout<<A->data<<" ";
        A=A->link;
    }
    cout<<endl;
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



ostream & operator<<(ostream &os,node*a){           //os(can be any other name) here is equivalent to cout.
    print(a);                                   
    return os;          //for cascading
}


node* merge(node*a,node*b){
    //base case
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    node* head;
    if(a->data<b->data){
        head=a;
        a->link=merge(a->link,b);
    }
    else{
        head=b;
        b->link=merge(a,b->link);
    }
    return head;
}

node* mergeSort(node*l){
    //base case
    if(l==NULL || l->link==NULL){
        return l; 
    }
    //rec case
    node*mid=findmidPoint(l);
    node*a=l;
    node*b=mid->link;
    mid->link=NULL;
    a=mergeSort(a);
    b=mergeSort(b);
    return merge(a,b);
    
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

void findElement(int k,node*A){
    node*fast=A;
    node*slow=A;
    const int pos=k;
    while(k--){
        fast=fast->link;
        
    }
    while(fast!=NULL){
        fast=fast->link;
        slow=slow->link;
    }
    cout<<"Element at "<<pos<<" position from end is:"<<slow->data<<endl;
    return;
}

int main()
{
    node*A=NULL;node*B=NULL;node*E=NULL;
    insert(1,A);
    insert(3,A);
    insert(6,A);
    insert(2,B);
    insert(4,B);
    insert(5,B);
    insert(7,B);
    insert(8,B);
    insert(9,B);
    
    insert(3,E);
    insert(8,E);
    insert(6,E);
    insert(1,E);
    insert(9,E);
    insert(7,E);
    insert(4,E);
    insert(5,E);
    insert(2,E);
    
    // findElement(6,A);       //finding kth element from end without calculating length
    cout<<A<<endl<<B<<endl;
    // print(A);
    // print(B);
    node*c=merge(A,B);
    cout<<c<<endl;
    cout<<E<<endl;
    node *D=mergeSort(E);
    cout<<D<<endl;
    // delete c;
    return 0;
}
