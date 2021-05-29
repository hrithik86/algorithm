/* Sort a k sorted doubly linked list
Similar question: Sort a nearly sorted (or K sorted) array
T.C: O(N*logK)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct compare {
    bool operator()(Node*p1,Node* p2){
        return p1->data > p2->data;
    }
};

Node *sortAKSortedDLL(Node *head, int k)
{
	priority_queue<Node*,vector<Node*>,compare>pq;
    Node*newhead=NULL;
	Node*last=NULL;
    Node*temp=head;
    k++;
    while(k && temp!=NULL){
        pq.push(temp);
        temp=temp->next;
        k--;
    }
   
    while(temp!=NULL){
        Node*x=pq.top();
        pq.pop();
        if(newhead==NULL){
            newhead=x;
            newhead->prev=NULL;
            last=x;
        }
        else{
            last->next=x;
            x->prev=last;
            last=x;
        }
        pq.push(temp);
        temp=temp->next;
    }
    while(!pq.empty()){
        Node*x=pq.top();
        pq.pop();
       	last->next=x;
        x->prev=last;
        last=x;
    }
    last->next=NULL;
    return newhead;
}

void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node =
          (struct Node*)malloc(sizeof(struct Node));
 
    // put in the data
    new_node->data = new_data;
 
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;
 
    // link the old list off the new node
    new_node->next = (*head_ref);
 
    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    // move the head to point to the new node
    (*head_ref) = new_node;
}
 

void printList(struct Node* head)
{
    // if list is empty
    if (head == NULL)
        cout << "Doubly Linked list empty";
 
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
 
    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
 
    int k = 2;

    cout << "Original Doubly linked list:\n";
    printList(head);
    head = sortAKSortedDLL(head, k);
 
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);
 
    return 0;
}
