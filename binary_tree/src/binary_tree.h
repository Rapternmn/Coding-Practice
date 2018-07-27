#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int key;
};

Node* newNode(int data);

// All Traversals
void printPostorder(struct Node* node);
void printInorder(struct Node* node);
void printPreorder(struct Node* node);

void inOrder(struct Node *root); // Without recurssion
void iterativePreorder(node *root);

void NthInorder(struct Node* node, int n);
void NthPostordernode(struct Node* root, int N)

void insert(struct Node* temp, int key);

int findLevel(Node *root, int k, int level);

Node *findDistUtil(Node* root, int n1, int n2, 
					int &d1, int &d2, int &dist, int lvl) ;

int findDistance(Node *root, int n1, int n2);

void deletDeepest(struct Node *root,struct Node * d_node);

void deletion(struct Node* root, int key);

bool isMirror(struct Node* root1, struct Node* root2);

bool isSymmetric(struct Node* root);

int height(struct Node* node);

void printGivenLevel(struct Node* root, int level);

void printLevelOrder(struct Node* root);

void printLevelOrder_queue(struct Node* root);

// Spiral print level order
void printSpiral(struct Node* root);

void printGivenLevel(struct Node* root, int level, int ltr);

// Construction

struct Node* buildTree(char in[], char pre[], int inStrt, int inEnd) ;

int search(char arr[], int strt, int end, char value);

struct Node *findLCA(struct Node* root, int n1, int n2);

int diameter(struct node * tree);

int getLevelUtil(struct node *node, int data, int level);

int getLevel(struct node *node, int data);