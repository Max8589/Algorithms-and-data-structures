
#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode {
    int vertex;
    struct AdjListNode* next;
}AdjListNode;

typedef struct AdjList {
    struct AdjListNode *head;
} AdjList;

typedef struct Graph {
    int vertices;
    struct AdjList* array;
} Graph;

AdjListNode* newAdjListNode(int vertex) {
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof (AdjListNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int verticesCount) {
    struct Graph* temp = (Graph*) malloc(sizeof(Graph));
    temp->vertices = verticesCount;
    temp->array = (AdjList*) malloc(verticesCount * sizeof(AdjList));
    
    int i;
    for (i = 0; i < verticesCount; ++i)
        temp->array[i].head = NULL;
    return temp;
}

void addEdge(Graph* temp, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = temp->array[src].head;
    temp->array[src].head = newNode;
    newNode = newAdjListNode(src);
    newNode->next = temp->array[dest].head;
    temp->array[dest].head = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        AdjListNode* pCrawl = graph->array[i].head;
        printf("\nVertex %d\nHead ", i);
        while (pCrawl)
        {
            printf(" ->%d", pCrawl->vertex);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

//1. Написать рекурсивную функцию обхода графа в глубину.
int visited[100];
void DFS(Graph* graph, int v) {
    visited[v] = 1;
    AdjListNode* temp = graph->array[v].head;
    while(temp!=NULL) {
        if (!visited[temp->vertex]) {
            printf(" ->%d", temp->vertex);
            DFS(graph,temp->vertex);
        }
    temp=temp->next;
    }
}

int main(int argc, const char** argv) {
    int v = 6;
    struct Graph* g = createGraph(v);
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 5);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);

    printGraph(g);
    printf("\nDFS: %d", 0);
    DFS(g, 0);
    printf("\n");

    return 0;
}
