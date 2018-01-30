#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
	int value;
	node* next;
};

int main() {
	node* first = (node*)malloc(sizeof(node));
	first->next = (node*)malloc(sizeof(node));
	first->value = 13;
	node* second = first->next;
	second->value = 42;
	second->next = NULL;
	for(node* it = first; it!=NULL; it=it->next) {
		printf("%d\n", it->value);
	}
	free(second);
	free(first);
}
