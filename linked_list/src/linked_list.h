#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
// A linked list node
struct Node
{
	int data;
	struct Node *next;
};

void printList(struct Node *n);

void push(struct Node** head_ref, int new_data);

void insertAfter(struct Node* prev_node, int new_data);

void append(struct Node** head_ref, int new_data);

void deleteNode(struct Node **head_ref, int position);

void deleteList(struct Node** head_ref);

int getCount(struct Node* head);

int GetNth(struct Node* head, int index);

void printNthFromLast(struct Node *head, int n);

void recursiveReverse(struct Node** head_ref);

void reverse(struct Node** head_ref);

void printMiddle(struct Node *head);

void rotate(struct Node **head_ref, int k);

struct Node* SortedMerge(struct Node* a, struct Node* b) ;

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