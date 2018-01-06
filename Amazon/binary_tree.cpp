#include "binary_tree.h"

Node* newNode(int data)
{
	struct Node* newnode = new Node;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->key = data;
	return newnode;
}