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

void reverse_slist (struct node **head) {

	struct node *prev,*next,*current;
	prev = NULL;
	current = next = *head;

	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current	= next;
	}
	*head = prev;
}

void middle_slist (struct node *head) {
	struct node *slow,*fast;
	if (head == NULL) return;
	slow = fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	printf ("middle %d \n",slow->data);
	
}

void remove_dup (struct node *head) {
	struct node *ptr1,*ptr2;
	ptr1 = ptr2 = head;

	if (head == NULL) return;

	while (ptr1 && ptr1->next) {
		ptr2 = ptr1;
		while (ptr2->next != NULL) {
			if (ptr1->data == ptr2->next->data) {
				struct node *dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free (dup);
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

struct node *deleteN (struct node *head, int n) {

	struct node *t = head;
	int i;
	for (i = 1;i <=n && t!=NULL; ++i) {
		struct node *tmp = t;
		t = t->next;
		free (tmp);
	}
	return t;
}
void skipM_deleteN (struct node *head,int m, int n) {

	int count;
	struct node *ptr1,*ptr2;
	ptr1 = ptr2 = head;

	if (head == NULL) return;

	while (ptr1) {
		for (count = 1; count< m; ++count) {
	
			if (ptr1) ptr1 = ptr1->next;
			if (ptr1 == NULL) return;

			ptr2 = deleteN (ptr1->next,n);
			ptr1->next = ptr2;

		}
		ptr1 = ptr2;
	}

}

struct node * merge_slist (struct node *a, struct node *b) {
	struct node *result;
	if (a == NULL) return b;
	if (b == NULL) return a;


	if (a->data < b->data) {

		result = a;
		result->next = merge_slist(a->next,b);
	}
	else {
		result = b;
		result->next = merge_slist (a, b->next);
	}
	return result;
}

int main () {
	struct node *tmp = NULL;
	createNode (&tmp,6);
	createNode (&tmp,7);
	createNode (&tmp,4);
	createNode (&tmp,9);
	createNode (&tmp,9);
	createNode (&tmp,2);
	createNode (&tmp,0);
	createNode (&tmp,3);
	print_list (tmp);
	printf ("\nreverse\n\r");
	reverse_slist (&tmp);
	print_list (tmp);
	printf ("\nmiddle.\n\r");
	middle_slist (tmp);
	printf ("\nduplicate.\n\r");
	remove_dup(tmp);
	print_list (tmp);
	skipM_deleteN (tmp,2,2);
	print_list (tmp);

	return 0;
}
