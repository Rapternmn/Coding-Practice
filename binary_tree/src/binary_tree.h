#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int key;
};

struct Node* newNode(int data);

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

struct Node *findDistUtil(Node* root, int n1, int n2, 
					int &d1, int &d2, int &dist, int lvl) ;

int findDistance(Node *root, int n1, int n2);

void deletDeepest(struct Node *root,struct Node * d_node);

void deletion(struct Node* root, int key);

bool isMirror(struct Node* root1, struct Node* root2);

bool isSymmetric(struct Node* root);

int identicalTrees(struct node* a, struct node* b) ;

int height(struct Node* node);

void printGivenLevel(struct Node* root, int level);

void printLevelOrder(struct Node* root);

void printLevelOrder_queue(struct Node* root);

void printBoundary (struct node* root) ; // Boundary Traversal

void printBoundaryLeft(struct node* root) ; 

void printBoundaryRight(struct node* root) ;

void printLeaves(struct node* root) ;

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

int getLeafCount(struct node* node);

void leftViewUtil(struct node *root, int level, int *max_level) ;

void leftView(struct node *root) ;

void bottomView(Node *root) ;

void printVerticalOrder(Node* root) ;

bool isBalanced(struct node *root) ;

// Binary tree to DLL

node* bintree2listUtil(node* root) ;

node* bintree2list(node *root) ;

// Create a mirror of binary tree

void mirror(struct Node* node)  ;

// BST 

int isBST(struct node* node) ;

int isBSTUtil(struct node* node, int min, int max) ;

// Returns count of nodes in BST in range [low, high] 
int getCount(node *root, int low, int high) 

// BST : Root to leaf path sum

int checkThesum(struct Node *root, int path[], int i, int sum) ;

// Root to leaf path sum :

// Root to leaf path sum equal to a given number

// Given a binary tree and a number, return true if the tree has a root-to-leaf path such 
// that adding up all the values along the path equals the given number. 
// Return false if no such path can be found. 

bool hasPathSum(struct node* node, int sum) ;

// Sum of all the numbers that are formed from root to leaf paths

// Returns sum of all root to leaf paths. The first parameter is root 
// of current subtree, the second parameter is value of the number formed 
// by nodes from root to this node 
int treePathsSumUtil(struct node *root, int val) ;

// A wrapper function over treePathsSumUtil() 
int treePathsSum(struct node *root) ;

// Flatten Linked List

void flatten(struct Node* root) ;