#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
// A linked list node
struct Node
{
	int data;
	struct Node *next;
};

void printList(struct Node *n);									// Done

void push(struct Node** head_ref, int new_data);				// Done

void insertAfter(struct Node* prev_node, int new_data);			// Done

void append(struct Node** head_ref, int new_data);				// Done

void deleteNode(struct Node **head_ref, int position);			// Done

Node *deleteKthNode(struct Node *head, int k) ;					

void deleteList(struct Node** head_ref);						// Done

int getCount(struct Node* head);								// Done

int GetNth(struct Node* head, int index);						// Done

void printNthFromLast(struct Node *head, int n);				// Done

void recursiveReverse(struct Node** head_ref);					

void reverse(struct Node** head_ref);							// Done

void printMiddle(struct Node *head);

void rotate(struct Node **head_ref, int k);

struct Node* SortedMerge(struct Node* a, struct Node* b) ;

// Merge two sorted linked lists such that merged list is in reverse order

struct Node* SortedMergeReverse(Node *a, Node *b) ;

// Intersection of linkedlist

int getIntesectionNode(struct Node* head1, struct Node* head2) ;

// Add two Linked Lists

struct node* addSameSize(Node* head1, Node* head2, int* carry);

void addCarryToRemaining(Node* head1, Node* cur, int* carry, Node** result);

void addList(Node* head1, Node* head2, Node** result);

//least significant digit is first node
struct Node* addTwoLists (struct Node* first, struct Node* second);

// Flatten 
// Code : https://www.geeksforgeeks.org/flattening-a-linked-list/

struct Node* flatten (Node* root);

// Returns true if there is a loop in linked list 
// else returns false. 

bool detectLoop(struct Node *h) ; // Using Map

int detectloop_floyd(struct Node *list) ; // Using Two pointers

struct Node *reverse (struct Node *head, int k) ;  // Reverse Nodes in Set of K -- Nodes

void BinaryTree2DoubleLinkedList(node *root, node **head) ; // Convert Binary tree to DLL