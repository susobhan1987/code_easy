#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
struct node {
	int data;
	struct node *left,*right;
};

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

int giveHeight (struct node *root) {
	if (root == NULL) return 0;
	return MAX(giveHeight (root->left),giveHeight(root->right)) +1;
}

int giveSum (struct node *root) {
	if (root == NULL) return 0;
	return giveSum (root->right) + root->data + giveSum(root->left);
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
	printInorder(root);
	return 0;
}
