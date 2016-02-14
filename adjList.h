#ifndef _adjlist_h
#define _adjlist_h

typedef struct adjList {
    int num;
    t_node** queue;
}t_adjList;

extern t_adjList* createAdjList(int);
extern void addEdge(t_adjList*, int, int);
extern int isVisited(t_node*, int);

#endif
