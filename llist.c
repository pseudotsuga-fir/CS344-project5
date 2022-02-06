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
			printf(" -> %d", head->value);
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

struct node *llist_delete_head(struct node **head) {
	if(!*head) {
		return NULL;
	}
	struct node *tmp = *head;
	*head = tmp->next;
	return tmp;
}

void llist_free(struct node **head) {
	if(!*head) {
		return;
	}
	
	struct node *tmp = *head;
	struct node *next = tmp->next;    
    
	while(next) {
		tmp = next;
		next = tmp->next;
		free(tmp);
	}
	*head = NULL;
}

int main(int argc, char** argv) {
	struct node *head = NULL;
	for(int i=1; i < argc; i++) {
		if(strncmp(argv[i], "i", 1) == 0) {
			int value = atoi(argv[i + 1]);
			if(strcmp(argv[i], "ih") == 0) {
				struct node *n = node_alloc(value);
				llist_insert_head(&head, n);
			}
			else if(strcmp(argv[i], "it") == 0) {
				struct node *n = node_alloc(value);
				llist_insert_tail(&head, n);
			}
			i++;
			continue;
		}
		else if(strcmp(argv[i], "dh") == 0) {
			llist_delete_head(&head);
		}
		else if(strcmp(argv[i], "f") == 0) {
			llist_free(&head);
		}
		else if(strcmp(argv[i], "p") == 0) {
			llist_print(head);
		}
		else {
			printf("Unrecognized command: %s\n", argv[i]);
			printf("Usage: ./llist [ih INT | it INT | dh | f | p]\n");
		}
	}
}
