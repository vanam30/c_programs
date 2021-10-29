#include<stdio.h>
#include<stdlib.h>

struct node{
    int v;
    struct node* next;
};

struct graph{
    int nv;
    struct node** adjLists;
};

struct node* createNode(int v){
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->v = v;
    nn->next = NULL;
    return nn;
}

struct graph* createGraph(int v){
    struct graph* g = (struct graph*) malloc(sizeof(struct graph));
    g->nv = v;

    g->adjLists = malloc(v * sizeof(struct node*));

    int i;
    for(i = 0; i < v; i++){
        g->adjLists[i] = 0;
    }
    return g;
}
void addEdge(struct graph *g, int s, int d){
    struct node* n = createNode(d);
    n->next = g->adjLists[s];
    g->adjLists[s] = n;

    n = createNode(s);
    n->next = g->adjLists[d];
    g->adjLists[d]=n;
}
void printGraph(struct graph * g){
    int i;
    for(i = 0; i < g->nv; i++){
        struct node* t = g->adjLists[i];
        printf("\nVertex %d\n",i);
        while(t){
            printf("%d-> ", t->v);
            t = t->next;
        }
        printf("\n");
    }
}
int main()
{
    struct graph* g = createGraph(5);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 0, 3);
    addEdge(g, 1, 2);
    addEdge(g, 3, 4);
    addEdge(g, 4, 1);
    printGraph(g);
	return 0;
}
