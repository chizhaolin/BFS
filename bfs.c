#include <stdio.h>
#include "queue.h"
#include "adjList.h"

void bfs(t_adjList* pAdjList, int V)
{
    t_node* pVisitQueue = NULL;
    t_node* pStoredVisitQueue = NULL;//This queue is used to store the visited V, which will be used by function "isVisited()" to check if the V is visited or not.
    int index;

    pVisitQueue = enQueue(pVisitQueue, V);
    pStoredVisitQueue = enQueue(pStoredVisitQueue, V);

    printf("When the start position is %d, the result of BFS is: \n", V);

    while(!isEmpty(pVisitQueue)) {
        t_node* pHead;

        pHead = pVisitQueue;
        index = pHead->data;
        printf("%d ", pHead->data);

        pVisitQueue = deQueue(pVisitQueue);
        pHead = pAdjList->queue[index];
        while (pHead != NULL) {
            if (!isVisited(pStoredVisitQueue, pHead->data)) {
                pVisitQueue = enQueue(pVisitQueue, pHead->data);
                // Add the item to the visited queue
                pStoredVisitQueue = enQueue(pStoredVisitQueue, pHead->data);
            }
            pHead = pHead->next;
        }
    }

    printf("\n");
}

int main()
{
    t_adjList* pAdjList;

    pAdjList = createAdjList(4);
    addEdge(pAdjList, 0, 1);
    addEdge(pAdjList, 0, 2);
    addEdge(pAdjList, 1, 2);
    addEdge(pAdjList, 2, 0);
    addEdge(pAdjList, 2, 3);
    addEdge(pAdjList, 3, 3);

    bfs(pAdjList, 0);
    bfs(pAdjList, 1);
    bfs(pAdjList, 2);
    bfs(pAdjList, 3);

    return 0;
}

