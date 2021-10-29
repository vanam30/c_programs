#include<stdio.h>
#include<stdlib.h>

typedef struct Graph
{
    int V, E;
    int **adj;
} Graph;

Graph *adjMatrixOfGraph()
{
    int m, n, i;
    Graph *g = (Graph *) malloc(sizeof(Graph));
    if(!g)
    {
        printf("\nNo Memory allocated ");
        return NULL;
    }
    printf("Enter number of vertices and edges : ");
    scanf("%d %d", &g->V, &g->E);
    g->adj = (int**)malloc(sizeof(int *)*(g->V));
    for(i = 0; i < g->V;i++){
            g->adj[i] = (int*)malloc(sizeof(int)*(g->E));
    }
    for(m = 0; m <g->V; m++)
    {
        for(n = 0; n < g->E; n++)
        {
            g->adj[m][n] = 0;
        }
    }

    for(i = 0; i < g->E; i++)
    {
        printf("Enter node numbers in pair for an edges : ");
        scanf("%d %d", &m, &n);
        g->adj[m][n] = 1;
        g->adj[n][m] = 1;
    }
    return g;
}
void printGraph(Graph *g)
{
    int m, n;
    printf("\nAdjacency Matrix : \n");
    for(m = 0; m < g->V; m++)
    {
        for(n = 0; n < g->E; n++)
        {
            printf("%3d",g->adj[m][n]);
        }
        printf("\n");
    }
}
int main()
{
    Graph * G = adjMatrixOfGraph();
    printGraph(G);
    return 0;
}
