#include <stdio.h>
#include <malloc.h>
#include "queue.h"
#include "adjList.h"

t_adjList* createAdjList(int num)
{
    t_adjList* pAdjList;

    pAdjList = (t_adjList*)malloc(sizeof(t_adjList));
    if (pAdjList != NULL) {
        pAdjList->num = num;
        pAdjList->queue = (t_node**)malloc(sizeof(t_node*) * num);
        if (pAdjList->queue != NULL) {
            int i;
            for (i = 0; i < num; i++) {
                pAdjList->queue[i] = enQueue(pAdjList->queue[i], i);
            }
        }
    }

    return pAdjList;
}

void addEdge(t_adjList * pAdjList, int V, int E)
{
    pAdjList->queue[V] = enQueue(pAdjList->queue[V], E);
}

int isVisited(t_node* pQueue, int V)
{
    while (pQueue != NULL) {
        if (pQueue->data == V)
            return 1;
        pQueue = pQueue->next;
    }
    return 0;
}
