#include "binary_tree.h"

Node* newNode(int data)
{
	struct Node* newnode = new Node;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->key = data;
	return newnode;
}

// All Traversals, Recursive

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    cout << node->data << " ";
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    cout << node->data << " ";
 
    /* then recur on left sutree */
    printPreorder(node->left); 
 
    /* now recur on right subtree */
    printPreorder(node->right);
} 

// Inorder traversal without recurrsion

void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while(curr != NULL || s.empty() == false)
    {
    	while(curr != NULL)
    	{
    		s.push(curr);
    		curr = curr->left;
    	}

    	curr = s.top();
    	s.pop();

    	cout << curr->key << " ";

    	curr = curr->right ;

    }

}

// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node *root)
{
    // Base Case
    if (root == NULL)
       return;
 
    // Create an empty stack and push root to it
    stack<node *> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false)
    {
        // Pop the top item from stack and print it
        struct node *node = nodeStack.top();
        printf ("%d ", node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}

/* Given a binary tree, print its nth nodes of inorder*/
void NthInorder(struct Node* node, int n)
{
    static int count = 0;
    if (node == NULL)
        return;

    if (count <= n) {

        /* first recur on left child */
        NthInorder(node->left, n);
        count++;

        // when count = n then print element
        if (count == n)
            printf("%d ", node->data);

        /* now recur on right child */
        NthInorder(node->right, n);
    }
}

// function to find the N-th node in the postorder
// traversal of a given binary tree
void NthPostordernode(struct Node* root, int N)
{
    static int flag = 0;
 
    if (root == NULL)
        return;
 
    if (flag <= N) {
 
        // left recursion
        NthPostordernode(root->left, N);
 
        // right recursion
        NthPostordernode(root->right, N);
 
        flag++;
 
        // prints the n-th node of preorder traversal
        if (flag == N)
            cout << root->data;
    }
}
/*function to insert element in binary tree */

void insert(struct Node* temp, int key)
{
	queue<struct Node*> q;

	q.push(temp);

	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if(temp->left == NULL)
		{
			q->left = newnode(key);
			break;
		}
		else
			q.push(temp->left);
		if(temp->right == NULL)
		{
			q->right = newnode(key);
			break;
		}
		else
			q.push(temp->right);
	}
}

int findLevel(Node *root, int k, int level)
{
	if(root == NULL)
		return -1 ;

	if(root->key == k)
		return level;

	int l = findLevel(root->left,k,level+1);

	if(l != -1)
		return l;
	else
		return findLevel(root->right,k,level+1);
}

Node *findDistUtil(Node* root, int n1, int n2, int &d1, 
                            int &d2, int &dist, int lvl)
{
	if(root == NULL)
		return NULL;

	if(root->key == n1)
	{
		d1 = lvl;
		return root;
	}

	if(root->key == n2)
	{
		d2 = lvl;
		return root;
	}


	Node* left_lca = findDistUtil(root->left, n1, n2, d1, d2, dist, lvl+1);
	Node* right_lca = findDistUtil(root->right, n1, n2, d1, d2, dist, lvl+1);

	if(left_lca && right_lca)
	{
		dist = d1 + d2 - 2*lvl;
		return root;
	}

	if(left_lca != NULL)
		return left_lca;
	
	else
		return right_lca;
}

int findDistance(Node *root, int n1, int n2)
{
	int d1 = -1, d2 = -1, dist;

    Node *lca = findDistUtil(root, n1, n2, d1, d2, dist, 1);

    if(d1 != -1 && d2 != -1)
    	return dist;

    if(d1 != -1)
    	return findLevel(lca, n2, 0);

    if(d2 != -1)
    	return findLevel(lca, n1, 0);

    return -1;
}

void deletDeepest(struct Node *root,struct Node * d_node)
{
	queue<struct Node*> q;
    q.push(root);

    while(!q.empty())
	{
		temp = q.front();
		q.pop();

		if(temp->right)
		{
			if(temp->right == d_node)
			{
				temp->right = NULL;
				delete(d_node);
				return;
			}
			else
				q.push(temp->right);
		}

		if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left=NULL;
                delete(d_node);
                return;
            }
            else
                q.push(temp->left);
        }

	}
}

/* function to delete element in binary tree */
void deletion(struct Node* root, int key)
{
	queue<struct Node*> q;

	q.push(temp);

	Node *key_node = NULL;
	Node* temp;

	while(!q.empty())
	{
		temp = q.front();
		q.pop();

		if(temp->key == key)
			key_node = temp;

		if(temp->left)
			q.push(temp->left);

		if(temp->right)
			q.push(temp->right);
	}

	int x = temp->key;
	deletDeepest(root, temp);
	key_node->key = x;
}

// Is Mirror Tree /Symmetric Tree

bool isMirror(struct Node* root1, struct Node* root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;

	if(root1 && root2 && root1->key == root2->key)
		return (isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left)) ;
	return false;
}

bool isSymmetric(struct Node* root)
{
	return isMirror(root, root);
}

int height(struct node* node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left 
      height and right heights */   
   return 1 + max(height(node->left), height(node->right));
} 

//Recurrsive

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 
// Using Queue

void printLevelOrder_queue(struct node* root)
{
    int rear, front;

    queue<struct Node*> q;

    struct node *temp_node = root;
 
    while (temp_node)
    {
        printf("%d ", temp_node->data);
 
        /*Enqueue left child */
        if (temp_node->left)
            q.push(temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right)
        	q.push(temp_node->right);           
 
        /*Dequeue node and make it temp_node*/
        temp_node = q.front();
        q.pop();
    }
}

// Spiral print levelorder

/* Function to print spiral traversal of a tree*/
void printSpiral(struct node* root)
{
    int h = height(root);
    int i;
 
    /*ltr -> Left to Right. If this variable is set,
      then the given level is traverseed from left to right. */
    bool ltr = false;
    for(i=1; i<=h; i++)
    {
        printGivenLevel(root, i, ltr);
 
        /*Revert ltr to traverse next level in opposite order*/
        ltr = !ltr;
    }
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level, int ltr)
{
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        if(ltr)
        {
            printGivenLevel(root->left, level-1, ltr);
            printGivenLevel(root->right, level-1, ltr);
        }
        else
        {
            printGivenLevel(root->right, level-1, ltr);
            printGivenLevel(root->left, level-1, ltr);
        }
    }
}

// Spiral -> Iterative

void printSpiral(struct node *root)
{
    if (root == NULL)  return;   // NULL check
 
    // Create two stacks to store alternate levels
    stack<struct node*> s1;  // For levels to be printed from right to left
    stack<struct node*> s2;  // For levels to be printed from left to right
 
    // Push first level to first stack 's1'
    s1.push(root);
 
    // Keep ptinting while any of the stacks has some nodes
    while (!s1.empty() || !s2.empty())
    {
        // Print nodes of current level from s1 and push nodes of
        // next level to s2
        while (!s1.empty())
        {
            struct node *temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
 
            // Note that is right is pushed before left
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }
 
        // Print nodes of current level from s2 and push nodes of
        // next level to s1
        while (!s2.empty())
        {
            struct node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
 
            // Note that is left is pushed before right
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}


// Construction & Conversion :


/* Recursive function to construct binary of size len from
   Inorder traversal in[] and Preorder traversal pre[].  Initial values
   of inStrt and inEnd should be 0 and len -1.  The function doesn't
   do any error checking for cases where inorder and preorder
   do not form a tree */
struct Node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
  static int preIndex = 0;
 
  if(inStrt > inEnd)
     return NULL;
 
  /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
  struct node *tNode = newNode(pre[preIndex++]);
 
  /* If this node has no children then return */
  if(inStrt == inEnd)
    return tNode;
 
  /* Else find the index of this node in Inorder traversal */
  int inIndex = search(in, inStrt, inEnd, tNode->data);
 
  /* Using index in Inorder traversal, construct left and
     right subtress */
  tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);
 
  return tNode;
}
 
/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
   The function assumes that value is present in in[] */
int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}

// LCA

struct Node *findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1 || root->key == n2)
        return root;
 
    // Look for keys in left and right subtrees
    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}

// Diameter 

/* Function to get diameter of a binary tree */
int diameter(struct node * tree)
{
   /* base case where tree is empty */
   if (tree == NULL)
     return 0;
 
  /* get the height of left and right sub-trees */
  int lheight = height(tree->left);
  int rheight = height(tree->right);
 
  /* get the diameter of left and right sub-trees */
  int ldiameter = diameter(tree->left);
  int rdiameter = diameter(tree->right);
 
  /* Return max of following three
   1) Diameter of left subtree
   2) Diameter of right subtree
   3) Height of left subtree + height of right subtree + 1 */
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
} 


/* Helper function for getLevel().  It returns level of the data if data is
   present in tree, otherwise returns 0.*/
int getLevelUtil(struct node *node, int data, int level)
{
    if (node == NULL)
        return 0;
 
    if (node->data == data)
        return level;
 
    int downlevel = getLevelUtil(node->left, data, level+1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevelUtil(node->right, data, level+1);
    return downlevel;
}
 
/* Returns level of given data value */
int getLevel(struct node *node, int data)
{
    return getLevelUtil(node,data,1);
}