#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_Q_SIZE 500
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
struct node {
	int data;
	struct node *left,*right;
};

/* frunction prototypes */
struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);

struct node *createNode (int data) {
	struct node *tmp = (struct node *)malloc (sizeof(struct node));
	if (!tmp) return NULL;
	tmp->data = data;
	tmp->right = tmp->left = NULL;
	return tmp;
}

void printInorder (struct node *root) {
	if (root == NULL) return;
	printInorder (root->left);
	printf ("%d ,",root->data);
	printInorder(root->right);
}

void levelOrder (struct node *root) {
    int rear, front;
    struct node **queue = createQueue(&front, &rear);
    struct node *temp_node = root;
 
    while (temp_node)
    {
        printf("%d ", temp_node->data);
 
        /*Enqueue left child */
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);
 
        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
}

int giveHeight (struct node *root) {
	if (root == NULL) return 0;
	return MAX(giveHeight (root->left),giveHeight(root->right)) +1;
}

int giveSum (struct node *root) {
	if (root == NULL) return 0;
	return giveSum (root->right) + root->data + giveSum(root->left);
}

/*UTILITY FUNCTIONS*/
struct node** createQueue(int *front, int *rear)
{
    struct node **queue =
        (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);
 
    *front = *rear = 0;
    return queue;
}
 
void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
 
struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

struct node *createTree () {
	struct node *root = createNode(5);
	root->left = createNode(10);
	root->right = createNode(15);
	root->left->left = createNode(13);
	root->left->right = createNode(7);
	root->right->left = createNode(9);
	root->right->right = createNode (11);
	return root;
}
int main () {
	struct node *root = createTree ();
	printf ("Inorder :::\n\r");
	printInorder(root);
	printf ("\nLevel order :::\n\r");
	levelOrder(root);
	return 0;
}
