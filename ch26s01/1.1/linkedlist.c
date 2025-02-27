#include <stdlib.h>
#include "linkedlist.h"

static link head = NULL;
static link tail = NULL;

link make_node(int item)
{
	link p = malloc(sizeof *p);
	p->item = item;
	p->next = NULL;
	return p;
}

void free_node(link p)
{
	free(p);
}

link search(int key)
{
	link p;
	for (p = head; p; p = p->next)
		if (p->item == key)
			return p;
	return NULL;
}

void insert(link p)
{
	if (head == NULL) {
		tail = p;
	}
	p->next = head;
	head = p;
}

void insert_sort(link p)
{
    link *this_node = &head;
	if (*this_node == NULL) {
		head = p;
		tail = p;
		return;
	}

	for (; (*this_node)->next; this_node = &(*this_node)->next) {
		if (p->item >= (*this_node)->item && p->item <= (*this_node)->next->item) {
			p->next = (*this_node)->next;
			(*this_node)->next = p;
			return;
		}
	}

	if (p->item >= head->item) {
		(*this_node)->next = p;
		tail = p;
	} else {
		p->next = *this_node;
		*this_node = p;
	}
	return;
}

void delete_node(link p)
{
	link *pnext;
	for (pnext = &head; *pnext; pnext = &(*pnext)->next)
		if (*pnext == p) {
			*pnext = p->next;
			return;
		}
}

void traverse(void (*visit)(link))
{
	link p;
	for (p = head; p; p = p->next)
		visit(p);
}

void destroy(void)
{
	link q, p = head;
	head = NULL;
	while (p) {
		q = p;
		p = p->next;
		free_node(q);
	}
}

void push(link p)
{
	insert(p);
}

link pop(void)
{
	if (head == NULL)
		return NULL;
	else {
		link p = head;
		head = head->next;
		return p;
	}
}

void enqueue(link p)
{
	tail->next = p;
	tail = p;
}

void dequeue(void)
{
	link tmp = head;
	delete_node(head);
	free_node(tmp);
}

void reverse(void)
{
	size_t size = 5;
	int *buf = malloc(size);
	int i = 0;
	link p;

	for (p = head; p;) {
		if (i >= size) {
			size = expand(buf, size);
		}
		buf[i++] = p->item;
		link pre = p;
		p = p->next;
		delete_node(pre);
		free_node(pre);
	}

	for (int j = 0; j < i; j++) {
		link new_p = make_node(buf[j]);
		insert(new_p);
	}

	free(buf);
	buf = NULL;
}

int expand(int array[], size_t size)
{
	size <<= 1;
	int temp[size];
	for (int i = 0; i < (size >> 1); i++) {
		temp[i] = array[i];
	}

	free(array);
	array = malloc(size);
	
	for (int i = 0; i < (size >> 1); i++) {
		array[i] = temp[i];
	}

	return size;
}
