#include <stdio.h>
#include "linkedlist.h"

void print_item(link p)
{
	printf("%d\n", p->item); 
}

int main(void)
{
	link p = make_node(10);
	insert_sort(p);
	p = make_node(5);
	insert_sort(p);
	p = make_node(90);
	insert_sort(p);
	p = make_node(90);
	insert_sort(p);
	p = make_node(90);
	insert_sort(p);
	p = make_node(9);
	insert_sort(p);
	reverse();
	p = search(5);
	delete_node(p);
	free_node(p);
	traverse(print_item);
	destroy();

	p = make_node(100);
	push(p);
	p = make_node(200);
	push(p);
	p = make_node(250);
	push(p);
	
	p = make_node(6);
	enqueue(p);
	dequeue();
	while (p = pop()) {
		print_item(p);
		free_node(p);
	}

	return 0;
}
