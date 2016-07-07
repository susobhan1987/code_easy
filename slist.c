#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

void createNode (struct node **head_ref,int data) {

	struct node *tmp = malloc(sizeof (struct node));
	if (!tmp) return;
	tmp->data = data;
	tmp->next = NULL;
	tmp->next = *head_ref;
	*head_ref = tmp;
}

void print_list (struct node *head) {
	struct node *tmp = head;

	while (tmp) {
		printf ("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf ("\n\r");
}

int main () {
	struct node *tmp = NULL;
	createNode (&tmp,6);
	createNode (&tmp,7);
	createNode (&tmp,4);
	createNode (&tmp,9);
	createNode (&tmp,2);
	createNode (&tmp,0);
	print_list (tmp);
	return 0;
}
