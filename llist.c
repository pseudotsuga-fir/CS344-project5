// Andrew Hepworth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

struct node *node_alloc(int value) {
	struct node *node;
	node = malloc(sizeof *node);
	node->value = value;
	node->next = NULL;
	return node;
}

void node_free(struct node *n) {
	free(n);
}

void llist_print(struct node *head) {
	if(!head) {
		printf("[empty]\n");
	}
	else {
		printf("%d", head->value);
		head = head->next;
		while(head) {
			printf("-> %d", head->value);
			head = head->next;
		}
		printf("\n");
	}
	
}

void llist_insert_head(struct node **head, struct node *n) {
	n->next = *head;
	*head = n;
}

void llist_insert_tail(struct node **head, struct node *n) {
	if(!*head) {
		*head = n;
	}
	else {
		if((*head)->next) {
			llist_insert_tail(&(*head)->next, n);
		}
		else {
			(*head)->next = n;
		}
	}
}

int main(int argc, char** argv) {
	struct node *head = NULL;
//	for(int i=1; i < argc; i++) {
//		if(strncmp(argv[i], "i", 1) == 0) {
//
//		}
//	}
	struct node *n = node_alloc(56);
	struct node *n2 = node_alloc(2);
	struct node *n3 = node_alloc(68);
	struct node *n4 = node_alloc(18);
	llist_insert_tail(&head, n);
	llist_insert_tail(&head, n2);
	llist_insert_tail(&head, n3);
	llist_insert_head(&head, n4);
	llist_print(head);

}
