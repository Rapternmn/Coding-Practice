#include "linked_list.h"

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
}

/* Given a reference (pointer to pointer) to the head of a list and 
   an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    new_node->data  = new_data;
 
    new_node->next = (*head_ref);
 
    (*head_ref)    = new_node;
}

void insertAfter(struct Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
 
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
 
    new_node->data  = new_data;
 
    new_node->next = prev_node->next;
 
    prev_node->next = new_node;
}

void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;  /* used in step 5*/

    new_node->data  = new_data;

    /* 3. This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
    
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}


/* Given a reference (pointer to pointer) to the head of a list
   and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int position)
{
   // If linked list is empty
   if (*head_ref == NULL)
      return;
 
   // Store head node
   struct Node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }
 
    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;
 
    // If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL)
         return;
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node *next = temp->next->next;
 
    // Unlink the node from linked list
    free(temp->next);  // Free memory
 
    temp->next = next;  // Unlink the deleted node from list
}


// Deletes every k-th node and returns head 
// of modified list. 
Node *deleteKthNode(struct Node *head, int k) 
{ 
    // If linked list is empty 
    if (head == NULL) 
        return NULL; 
  
    if (k == 1) 
    { 
       freeList(head); 
       return NULL; 
    } 
  
    // Initialize ptr and prev before starting 
    // traversal. 
    struct Node *ptr = head, *prev = NULL; 
  
    // Traverse list and delete every k-th node 
    int count = 0; 
    while (ptr != NULL) 
    { 
        // increment Node count 
        count++; 
  
        // check if count is equal to k 
        // if yes, then delete current Node 
        if (k == count) 
        { 
            // put the next of current Node in 
            // the next of previous Node 
            delete(prev->next); 
            prev->next = ptr->next; 
  
            // set count = 0 to reach further 
            // k-th Node 
            count = 0; 
        } 
  
        // update prev if count is not 0 
        if (count != 0) 
            prev = ptr; 
  
        ptr = prev->next; 
    } 
  
    return head; 
} 


/* Function to delete the entire linked list */
void deleteList(struct Node** head_ref)
{
   /* deref head_ref to get the real head */
   struct Node* current = *head_ref;
   struct Node* next;
 
   while (current != NULL) 
   {
       next = current->next;
       free(current);
       current = next;
   }
   
   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;
}

/* Counts no. of nodes in linked list */
int getCount(struct Node* head)
{
    int count = 0;  // Initialize count
    struct Node* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Takes head pointer of 
// the linked list and index
// as arguments and return
// data at index
int GetNth(struct Node* head, 
                  int index)
{
     
    struct Node* current = head;
     
     // the index of the 
     // node we're currently
     // looking at
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
            return(current->data);
        count++;
        current = current->next;
    }
 
    /* if we get to this line, 
       the caller was asking
       for a non-existent element
       so we assert fail */
    assert(0);             
}

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node *head, int n)
{
  struct Node *main_ptr = head;
  struct Node *ref_ptr = head;
 
  int count = 0;
  if(head != NULL)
{
     while( count < n )
     {
        if(ref_ptr == NULL)
        {
           printf("%d is greater than the no. of "
                    "nodes in list", n);
           return;
        }
        ref_ptr = ref_ptr->next;
        count++;
     } /* End of while*/
 
     while(ref_ptr != NULL)
     {
        main_ptr = main_ptr->next;
        ref_ptr  = ref_ptr->next;
     }
     printf("Node no. %d from last is %d ", 
              n, main_ptr->data);
  }
}

/* Function to reverse the linked list */
void recursiveReverse(struct Node** head_ref)
{
    struct Node* first;
    struct Node* rest;
      
    /* empty list */
    if (*head_ref == NULL)
       return;   
 
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;  
    rest  = first->next;
 
    /* List has only one node */
    if (rest == NULL)
       return;   
 
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;  
     
    /* tricky step -- see the diagram */
    first->next  = NULL;          
 
    /* fix the head pointer */
    *head_ref = rest;              
}


void reverse(struct Node** head_ref)
{
    // Initialize current, previous and
    // next pointers
    Node *current = head;
    Node *prev = NULL, *next = NULL;


    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}

/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}


// This function rotates a linked list counter-clockwise and 
// updates the head. The function assumes that k is smaller 
// than size of linked list. It doesn't modify the list if 
// k is greater than or equal to size

void rotate(struct Node **head_ref, int k)
{
    if (k == 0)
        return;
 
    struct Node* current = *head_ref;

    int count = 1;
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }
 
    if (current == NULL)
        return;
 
    struct Node *kthNode = current;

    while (current->next != NULL)
        current = current->next;
 
    current->next = *head_ref;
 
    *head_ref = kthNode->next;
 
    kthNode->next = NULL;
}

struct Node* SortedMerge(struct Node* a, struct Node* b) 
{
    struct Node* result = NULL;
   
    /* Base cases */
    if (a == NULL) 
        return(b);
    else if (b==NULL) 
        return(a);
   
    /* Pick either a or b, and recur */
    if (a->data <= b->data) 
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}

struct Node* SortedMergeReverse(Node *a, Node *b)
{ 
    // If both lists are empty 
    if (a==NULL && b==NULL) return NULL; 
  
    // Initialize head of resultant list 
    Node *res = NULL; 
  
    // Traverse both lists while both of then 
    // have nodes. 
    while (a != NULL && b != NULL) 
    { 
        // If a's current value is smaller or equal to 
        // b's current value. 
        if (a->key <= b->key) 
        { 
            // Store next of current Node in first list 
            Node *temp = a->next; 
  
            // Add 'a' at the front of resultant list 
            a->next = res; 
            res = a; 
  
            // Move ahead in first list 
            a = temp; 
        } 
  
        // If a's value is greater. Below steps are similar 
        // to above (Only 'a' is replaced with 'b') 
        else
        { 
            Node *temp = b->next; 
            b->next = res; 
            res = b; 
            b = temp; 
        } 
    } 
  
    // If second list reached end, but first list has 
    // nodes. Add remaining nodes of first list at the 
    // front of result list 
    while (a != NULL) 
    { 
        Node *temp = a->next; 
        a->next = res; 
        res = a; 
        a = temp; 
    } 
  
    // If first list reached end, but second list has 
    // node. Add remaining nodes of first list at the 
    // front of result list 
    while (b != NULL) 
    { 
        Node *temp = b->next; 
        b->next = res; 
        res = b; 
        b = temp; 
    } 
  
    return res; 
} 

int getIntesectionNode(struct Node* head1, struct Node* head2)
{
  int c1 = getCount(head1);
  int c2 = getCount(head2);
  int d;
 
  if(c1 > c2)
  {
    d = c1 - c2;
    return _getIntesectionNode(d, head1, head2);
  }
  else
  {
    d = c2 - c1;
    return _getIntesectionNode(d, head2, head1);
  }
}
 
/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
int _getIntesectionNode(int d, struct Node* head1, struct Node* head2)
{
    int i;
    struct Node* current1 = head1;
    struct Node* current2 = head2;
   
    for(i = 0; i < d; i++)
    {
        if(current1 == NULL)
        {  return -1; }
        current1 = current1->next;
    }
   
    while(current1 !=  NULL && current2 != NULL)
    {
        if(current1 == current2)
          return current1->data;
        current1= current1->next;
        current2= current2->next;
    }
   
    return -1;
}

// Add two linked lists : most significant node is first node

struct node* addSameSize(Node* head1, Node* head2, int* carry)
{
    // Since the function assumes linked lists are of same size,
    // check any of the two head pointers
    if (head1 == NULL)
        return NULL;
 
    int sum;
 
    // Allocate memory for sum node of current two nodes
    Node* result = (Node *)malloc(sizeof(Node));
 
    // Recursively add remaining nodes and get the carry
    result->next = addSameSize(head1->next, head2->next, carry);
 
    // add digits of current nodes and propagated carry
    sum = head1->data + head2->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;
 
    // Assigne the sum to current node of resultant list
    result->data = sum;
 
    return result;
}

// This function is called after the smaller list is added to the bigger
// lists's sublist of same size.  Once the right sublist is added, the carry
// must be added toe left side of larger list to get the final result.
void addCarryToRemaining(Node* head1, Node* cur, int* carry, Node** result)
{
    int sum;
 
    // If diff. number of nodes are not traversed, add carry
    if (head1 != cur)
    {
        addCarryToRemaining(head1->next, cur, carry, result);
 
        sum = head1->data + *carry;
        *carry = sum/10;
        sum %= 10;
 
        // add this node to the front of the result
        push(result, sum);
    }
}

// The main function that adds two linked lists represented by head1 and head2.
// The sum of two lists is stored in a list referred by result
void addList(Node* head1, Node* head2, Node** result)
{
    Node *cur;
 
    // first list is empty
    if (head1 == NULL)
    {
        *result = head2;
        return;
    }
 
    // second list is empty
    else if (head2 == NULL)
    {
        *result = head1;
        return;
    }
 
    int size1 = getSize(head1);
    int size2 = getSize(head2) ;
 
    int carry = 0;
 
    // Add same size lists
    if (size1 == size2)
        *result = addSameSize(head1, head2, &carry);
 
    else
    {
        int diff = abs(size1 - size2);
 
        // First list should always be larger than second list.
        // If not, swap pointers
        if (size1 < size2)
            swapPointer(&head1, &head2);
 
        // move diff. number of nodes in first list
        for (cur = head1; diff--; cur = cur->next);
 
        // get addition of same size lists
        *result = addSameSize(cur, head2, &carry);
 
        // get addition of remaining first list and carry
        addCarryToRemaining(head1, cur, &carry, result);
    }
 
    // if some carry is still there, add a new node to the fron of
    // the result list. e.g. 999 and 87
    if (carry)
        push(result, carry);
}

/* Adds contents of two linked lists and return the head node of resultant list */
// least significant digit is first node
struct Node* addTwoLists (struct Node* first, struct Node* second)
{
    struct Node* res = NULL; // res is head node of the resultant list
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;
 
    while (first != NULL || second != NULL) //while both lists exist
    {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i)  Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first? first->data: 0) + (second? second->data: 0);
 
        // update carry for next calulation
        carry = (sum >= 10)? 1 : 0;
 
        // update sum if it is greater than 10
        sum = sum % 10;
 
        // Create a new node with sum as data
        temp = newNode(sum);
 
        // if this is the first node then set it as head of the resultant list
        if(res == NULL)
            res = temp;
        else // If this is not the first node then connect it to the rest.
            prev->next = temp;
 
        // Set prev for next insertion
        prev  = temp;
 
        // Move first and second pointers to next nodes
        if (first) first = first->next;
        if (second) second = second->next;
    }
 
    if (carry > 0)
      temp->next = newNode(carry);
 
    // return head of the resultant list
    return res;
}

/*  Flatten Linked List 

Let us create the following linked list

        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45

Flat : 5->7->8->10->19->20->22->28->30->35->40->45->50.

Linked list node for flat :

// A Linked List Node
typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *down;
} Node;
 

*/

// The main function that flattens a given linked list
Node* flatten (Node* root)
{
    // Base cases
    if (root == NULL || root->right == NULL)
        return root;
 
    // Merge this list with the list on right side
    return merge( root, flatten(root->right) );
}

// A utsility function to merge two sorted linked lists 
Node* merge( Node* a, Node* b ) 
{ 
    // If first list is empty, the second list is result 
    if (a == NULL) 
        return b; 
  
    // If second list is empty, the second list is result 
    if (b == NULL) 
        return a; 
  
    // Compare the data members of head nodes of both lists 
    // and put the smaller one in result 
    Node* result; 
    if (a->data < b->data) 
    { 
        result = a; 
        result->down = merge( a->down, b ); 
    } 
    else
    { 
        result = b; 
        result->down = merge( a, b->down ); 
    } 
  
    return result; 
} 


bool detectLoop(struct Node *h) 
{ 
    unordered_set<Node *> s; 
    while (h != NULL) 
    { 
        // If this node is already present 
        // in hashmap it means there is a cycle 
        // (Because you we encountering the 
        // node for the second time). 
        if (s.find(h) != s.end()) 
            return true; 
  
        // If we are seeing the node for 
        // the first time, insert it in hash 
        s.insert(h); 
  
        h = h->next; 
    } 
  
    return false; 
} 

int detectloop_floyd(struct Node *list) 
{ 
    struct Node  *slow_p = list, *fast_p = list; 
   
    while (slow_p && fast_p && fast_p->next ) 
    { 
        slow_p = slow_p->next; 
        fast_p  = fast_p->next->next; 
        if (slow_p == fast_p) 
        { 
           printf("Found Loop"); 
           return 1; 
        } 
    } 
    return 0; 
} 


struct Node *reverse (struct Node *head, int k) 
{ 
    struct Node* current = head; 
    struct Node* next = NULL; 
    struct Node* prev = NULL; 
    int count = 0;    
      
    /*reverse first k nodes of the linked list */ 
    while (current != NULL && count < k) 
    { 
        next  = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
        count++; 
    } 
      
    /* next is now a pointer to (k+1)th node  
       Recursively call for the list starting from current. 
       And make rest of the list as next of first node */
    if (next !=  NULL) 
       head->next = reverse(next, k);  
  
    /* prev is new head of the input list */
    return prev; 
} 

void BinaryTree2DoubleLinkedList(node *root, node **head) 
{ 
    // Base case 
    if (root == NULL) return; 
  
    // Initialize previously visited node as NULL. This is 
    // static so that the same value is accessible in all recursive 
    // calls 
    static node* prev = NULL; 
  
    // Recursively convert left subtree 
    BinaryTree2DoubleLinkedList(root->left, head); 
  
    // Now convert this node 
    if (prev == NULL) 
        *head = root;
    else
    { 
        root->left = prev;
        prev->right = root;
    } 
    prev = root; 
  
    // Finally convert right subtree 
    BinaryTree2DoubleLinkedList(root->right, head); 
} 

/* Function to pairwise swap elements of a linked list */
void pairWiseSwap(struct Node *head) 
{ 
    struct Node *temp = head; 
  
    /* Traverse further only if there are at-least two nodes left */
    while (temp != NULL && temp->next != NULL) 
    { 
        /* Swap data of node with its next node's data */
        swap(&temp->data, &temp->next->data); 
  
        /* Move temp by 2 for the next pair */
        temp = temp->next->next; 
    } 
} 

/* Function to pairwise swap elements of a linked list */
void pairWiseSwap_inplace(struct Node **head) 
{ 
    // If linked list is empty or there is only one node in list 
    if (*head == NULL || (*head)->next == NULL) 
        return; 
  
    // Initialize previous and current pointers 
    struct Node *prev = *head; 
    struct Node *curr = (*head)->next; 
  
    *head = curr;  // Change head before proceeeding 
  
    // Traverse the list 
    while (true) 
    { 
        struct Node *next = curr->next; 
        curr->next = prev; // Change next of current as previous node 
  
        // If next NULL or next is the last node 
        if (next == NULL || next->next == NULL) 
        { 
            prev->next = next; 
            break; 
        } 
  
        // Change next of previous to next next 
        prev->next = next->next; 
  
        // Update previous and curr 
        prev = next; 
        curr = prev->next; 
    }

}


/* The function removes duplicates from a sorted list */
void removeDuplicates(struct Node* head) 
{ 
    /* Pointer to traverse the linked list */
    struct Node* current = head; 
  
    /* Pointer to store the next pointer of a node to be deleted*/
    struct Node* next_next;  
    
    /* do nothing if the list is empty */
    if (current == NULL)  
       return;  
  
    /* Traverse the list till last node */
    while (current->next != NULL)  
    { 
       /* Compare current node with next node */
       if (current->data == current->next->data)  
       { 
           /* The sequence of steps is important*/               
           next_next = current->next->next; 
           free(current->next); 
           current->next = next_next;   
       } 
       else /* This is tricky: only advance if no deletion */
       { 
          current = current->next;  
       } 
    } 
} 


/* This function detects and removes loop in the list 
  If loop was there in the list then it returns 1, 
  otherwise returns 0 */
int detectAndRemoveLoop(struct Node *list) 
{ 
    struct Node  *slow_p = list, *fast_p = list; 
  
    while (slow_p && fast_p && fast_p->next) 
    { 
        slow_p = slow_p->next; 
        fast_p  = fast_p->next->next; 
  
        /* If slow_p and fast_p meet at some point then there 
           is a loop */
        if (slow_p == fast_p) 
        { 
            removeLoop(slow_p, list); 
  
            /* Return 1 to indicate that loop is found */
            return 1; 
        } 
    } 
  
    /* Return 0 to indeciate that ther is no loop*/
    return 0; 
} 
  
/* Function to remove loop. 
 loop_node --> Pointer to one of the loop nodes 
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct Node *loop_node, struct Node *head) 
{
   struct Node *ptr1; 
   struct Node *ptr2; 
  
   /* Set a pointer to the beging of the Linked List and 
      move it one by one to find the first node which is 
      part of the Linked List */
   ptr1 = head;
   while (1)
   { 
     /* Now start a pointer from loop_node and check if it ever 
       reaches ptr2 */
     ptr2 = loop_node; 
     while (ptr2->next != loop_node && ptr2->next != ptr1) 
         ptr2 = ptr2->next; 
  
     /* If ptr2 reahced ptr1 then there is a loop. So break the 
        loop */
     if (ptr2->next == ptr1) 
        break; 
  
     /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
     ptr1 = ptr1->next; 
   } 
  
   /* After the end of loop ptr2 is the last node of the loop. So 
     make next of ptr2 as NULL */
   ptr2->next = NULL; 
} 

// Returns count of nodes present in loop. 

int countNodes(struct Node *n) 
{ 
   int res = 1; 
   struct Node *temp = n; 
   while (temp->next != n) 
   { 
      res++; 
      temp = temp->next; 
   } 
   return res; 
}

int countNodesinLoop(struct Node *list) 
{ 
    struct Node  *slow_p = list, *fast_p = list; 
  
    while (slow_p && fast_p && fast_p->next) 
    { 
        slow_p = slow_p->next; 
        fast_p  = fast_p->next->next; 
  
        /* If slow_p and fast_p meet at some point 
           then there is a loop */
        if (slow_p == fast_p) 
            return countNodes(slow_p); 
    } 
  
    /* Return 0 to indeciate that ther is no loop*/
    return 0; 
} 

// This function clones a given linked list 
// in O(1) space 
Node* clone(Node *start) 
{ 
    Node* curr = start, *temp; 
  
    // insert additional node after 
    // every node of original list 
    while (curr) 
    { 
        temp = curr->next; 
  
        // Inserting node 
        curr->next = new Node(curr->data); 
        curr->next->next = temp; 
        curr = temp; 
    } 
  
    curr = start; 
  
    // adjust the random pointers of the 
    // newly added nodes 
    while (curr) 
    { 
        if(curr->next) 
            curr->next->random = curr->random ? curr->random->next : curr->random; 
  
        // move to the next newly added node by 
        // skipping an original node 
        curr = curr->next?curr->next->next:curr->next; 
    } 
  
    Node* original = start, *copy = start->next; 
  
    // save the start of copied linked list 
    temp = copy; 
  
    // now separate the original list and copied list 
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp; 
} 