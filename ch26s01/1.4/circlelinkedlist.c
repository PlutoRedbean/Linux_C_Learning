#include <stdlib.h>
#include "circlelinkedlist.h"

struct node sentinel = {0, &sentinel, &sentinel};
static link head = &sentinel;

link make_node(int item)
{
	link p = malloc(sizeof *p);
	p->item = item;
	p->prev = p->next = NULL;
	return p;
}

void free_node(link p)
{
	free(p);
}

link search(int key)
{
	link p;
	for (p = head->next; p != head; p = p->next)
		if (p->item == key)
			return p;
	return NULL;
}

void insert(link p)
{
	p->next = head->next;
	head->next->prev = p;
	head->next = p;
	p->prev = head;
}

void delete_node(link p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
}

void traverse(void (*visit)(link))
{
	link p;
	for (p = head->prev; p != head; p = p->prev)
		visit(p);
}

void destroy(void)
{
	link q, p = head->next;
	head->next = head;
	head->prev = head;
	while (p != head) {
		q = p;
		p = p->next;
		free_node(q);
	}
}

void enqueue(link p)
{
	insert(p);
}

link dequeue(void)
{
	if (head->prev == head)
		return NULL;
	else {
		link p = head->prev;
		delete_node(p);
		return p;
	}
}

void print_item(link p)
{
	printf("%c\n", p->item);
}

void josephus(int n, int m)
{
	int number = n;
	int count = 1;
	for (int i = 1; i <= n; i++) {
		link p = make_node(i);
		insert(p);
	}

	link p;
	for (p = head->prev; p->next != p->prev; count++) {
		if (p == head) {
			p = p->prev;
			continue;
		}
		if (count >= m) {
			count = 0;
			link remove = p;
			p = p->prev;
			printf("No.%-2d get killed\n", remove->item);
			delete_node(remove);
			free(remove);
			continue;
		}
		p = p->prev;
	}

	printf("\nLast man standing\n"
		   "No.%-2d remain\n", head->prev->item);

	destroy();
}
