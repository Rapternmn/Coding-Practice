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
