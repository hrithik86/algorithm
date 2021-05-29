// Reverse a doubly linked list in groups of given size
// Solution submitted on CodeStudio (Coding Ninjas)
#include <bits/stdc++.h>
using namespace std;

// A linked list node
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// Inserts a new node on the front of the list
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void printList(struct Node* node)
{
	struct Node* last;
	printf("Traversal in forward direction \n");
	while (node != NULL) {
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}
}

Node*reverseDLL(Node*head,int k){
    if(head==NULL) return NULL;
    int cnt=k;
    Node*temp=head;
    while(cnt && temp!=NULL){
        temp=temp->next;
        cnt--;
    }
    Node*nextHead=reverseDLL(temp,k);
    Node*curr=head;
    Node*past=NULL;
    while(curr!=temp){
        Node*future=curr->next;
        curr->next=past;
        curr->prev=future;
        past=curr;
        curr=future;
    }
    past->prev=NULL;
    head->next=nextHead;
    if(nextHead) nextHead->prev=head;
    return past;
}
Node* reverseDLLInGroups(Node* head, int k){	
    return reverseDLL(head,k);
}

int main()
{
	struct Node* head = NULL;
	push(&head, 12);
	push(&head, 11);
	push(&head, 10);
	push(&head, 9);
	push(&head, 8);
    printList(head);
    head=reverseDLLInGroups(head,3);
	printf("\nAfter reversal:\n");
	printList(head);
	getchar();
	return 0;
}
