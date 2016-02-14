#include <stdio.h>
#include <malloc.h>
#include "queue.h"

t_node* createNewNode(int data)
{
    t_node* pNew;

    pNew = (t_node*)malloc(sizeof(t_node));
    if (pNew != NULL) {
        pNew->data = data;
        pNew->next = NULL;
    }

    return pNew;
}

t_node* initQueue(int data)
{
    t_node* pNode;

    pNode = createNewNode(data);

    return pNode;
}

t_node* enQueue(t_node* pQueue, int data)
{
    if (pQueue == NULL) {
        pQueue = initQueue(data);
    }
    else {
        t_node* pTmp;
        t_node* pNew;
        
        pNew = createNewNode(data);

        pTmp = pQueue;
        while (pTmp->next != NULL) {
            pTmp = pTmp->next;
        }
        pTmp->next = pNew;
    }

    return pQueue;
}

t_node* deQueue(t_node* pQueue)
{
    if (pQueue != NULL) {
        if (pQueue->next == NULL) {
            free(pQueue);
            pQueue = NULL;
        }
        else {
            t_node* pDel;
            pDel = pQueue;
            pQueue = pDel->next;
            free(pDel);
            pDel = NULL;
        }
    }

    return pQueue;
}

int isEmpty(t_node* pQueue)
{
    return (pQueue == NULL);
}

void printQueue(t_node* pQueue)
{
    if (pQueue != NULL) {
        printf("The item of the queue are: \n");
        while (pQueue != NULL) {
            printf("%d ", pQueue->data);
            pQueue = pQueue->next;
        }
        printf("\n");
    }
    else {
        printf("Empty Queue!\n");
    }
}
/*
int main()
{
    t_node* pQueue; 

    pQueue = enQueue(pQueue, 1);
    pQueue = enQueue(pQueue, 2);
    pQueue = enQueue(pQueue, 3);
    pQueue = enQueue(pQueue, 4);
    pQueue = enQueue(pQueue, 5);
    printQueue(pQueue);

    pQueue = deQueue(pQueue);
    printQueue(pQueue);
    pQueue = deQueue(pQueue);
    printQueue(pQueue);
    pQueue = deQueue(pQueue);
    printQueue(pQueue);
    pQueue = deQueue(pQueue);
    printQueue(pQueue);
    pQueue = deQueue(pQueue);
    printQueue(pQueue);
    pQueue = deQueue(pQueue);
    printQueue(pQueue);

    return 0;
}
*/
