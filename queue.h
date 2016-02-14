
#ifndef _queue_h
#define _queue_h

typedef struct node {
    int data;
    struct node * next;
}t_node;

extern t_node* enQueue(t_node*, int);
extern t_node* deQueue(t_node*);
extern int isEmpty(t_node*);

#endif
