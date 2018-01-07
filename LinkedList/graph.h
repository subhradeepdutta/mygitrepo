#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode 
{
    int dest;
    struct AdjListNode* next;
}AdjacencyListNode;

typedef struct AdjList 
{
    AdjacencyListNode *head; 
}AdjacencyList;
 

typedef struct Graph 
{
    int V;
    AdjacencyList* array;
}UndirectedGraph;

/*Function Prototpyes*/

AdjacencyListNode* newAdjListNode(int dest);

UndirectedGraph* createGraph(int V);

void addEdge(UndirectedGraph* graph, int src, int dest);

void printGraph(UndirectedGraph* graph);



