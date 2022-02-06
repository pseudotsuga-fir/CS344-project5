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

void llist_print(struct node *head){
	printf("%d\n", head->value);
}

int main(int argc, char** argv) {
//	for(int i=1; i < argc; i++) {
//		if(strncmp(argv[i], "i", 1) == 0) {
//
//		}
//	}
	struct node *head = node_alloc(56);
	llist_print(head);

}
