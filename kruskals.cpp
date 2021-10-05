# include <stdio.h>
# include <stdbool.h>
#include<time.h>
#include<windows.h>
# define MAX 50

int graph[MAX][MAX], order;

// undirected edge
struct edge {
    int a, b; // end vertices of the edge
    int wt; // weight of the edge
};

struct edgeSet {
    struct edge edges[MAX]; // edges
    int size; // size of the graph
};

struct edgeSet edgeList, spanEdges;

// find and union

bool find (int *connected, int point1, int point2) {
    return (connected[point1] == connected[point2]) ? true: false;
}

void union_ (int *connected, int point1, int point2) {
    int temp = connected[point2];
    for (int i = 0; i < order; i++) {
        if (connected[i] == temp) 
            connected[i] = connected[point1];
    }
}

// to sort the edge list
// algorithm used: bubble sort
void sort () {
    struct edge temp;
    
    for (int i = 0; i < edgeList.size - 1; i++) {
        for (int j = 0; j < edgeList.size - i - 1; j++) {
            if (edgeList.edges[j].wt > edgeList.edges[j + 1].wt) {
                temp = edgeList.edges[j];
                edgeList.edges[j] = edgeList.edges[j + 1];
                edgeList.edges[j + 1] = temp;
                Sleep(5);
            }
        }
    }
}

void krushkals() {
    int connected[MAX]; // array to identify connected vertices
    for (int i = 0; i < order; i++) 
        connected[i] = i;

    edgeList.size = 0; // no edges initially 

    // adding edges to edgeList 
    for (int i = 1; i < order; i++) {
        for (int j = 0; j < i; j++) { // only checking elements before diagonal
            if (graph[i][j] != 0) {
                edgeList.edges[edgeList.size].a = i;
                edgeList.edges[edgeList.size].b = j;
                edgeList.edges[edgeList.size].wt = graph[i][j];
                edgeList.size++;
            }
        }
    }

    // sort edges in edgesList according to their weights
    sort(); 

    spanEdges.size = 0; // no edges in the spanning tree yet
    
    for (int i = 0; i < edgeList.size; i++) {
        if (!find(connected, edgeList.edges[i].a, edgeList.edges[i].b)) { // if the vertices aren't connected yet
            // add the edge to the spanning tree
            spanEdges.edges[spanEdges.size] = edgeList.edges[i]; 
            spanEdges.size ++;
            // update that the vertices are now connected
            union_(connected, edgeList.edges[i].a, edgeList.edges[i].b); 
        }
    }
}

// displaying the minimum spanning tree
void displaySpanTree () {
    for (int i = 0; i < spanEdges.size; i++) {
        printf("Edge (%d, %d), wt - %d\n", 
        spanEdges.edges[i].a,
        spanEdges.edges[i].b,
        spanEdges.edges[i].wt
        );
    }
}

// calculate cost of the minimum spanning tree
int calcCost () {
    int cost = 0;
    for (int i = 0; i < spanEdges.size; i++)
        cost += spanEdges.edges[i].wt;
    return cost;
}

int main() {
    printf("Enter the order of the graph : ");
    scanf("%d",&order);
    printf("Enter the adjacency matrix of the graph : \n");
    for(int i=0;i<order;i++)
        for(int j=0;j<order;j++)
            scanf("%d",&graph[i][j]);
    clock_t s=clock();
    //delay(10);
    krushkals();
    clock_t  e = clock();
    displaySpanTree();
    printf("Minimum cost: %d", calcCost());
    printf("\nClock pulse before sorting : %d ",s);
    printf("\nClock pulse after sorting : %d ",e);
    printf("\nTime taken (by the processor) : %f",(float)(e-s)/CLOCKS_PER_SEC);
    return 0;
}