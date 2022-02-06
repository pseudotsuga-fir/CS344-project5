// Andrew Hepworth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

struct node *node_alloc(int value) {
	struct node *node;
	node->value = value;
	node->next = NULL;
	return malloc(sizeof *node);
}



int main(int argc, char** argv) {
	for(int i=1; i < argc; i++) {
		if(strncmp(argv[i], "i", 1) == 0) {

		}
	}
}
