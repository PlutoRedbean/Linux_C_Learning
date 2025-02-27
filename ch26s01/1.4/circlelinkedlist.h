#ifndef CIRCLELINKEDLIST_H
#define CIRCLELINKEDLIST_H

typedef struct node *link;
struct node {
	int item;
	link prev, next;
};

link make_node(int item);
void free_node(link p);
link search(int key);
void insert(link p);
void delete_node(link p);
void traverse(void (*visit)(link));
void destroy(void);
void enqueue(link p);
link dequeue(void);
void josephus(int, int);
void print_item(link p);

#endif
