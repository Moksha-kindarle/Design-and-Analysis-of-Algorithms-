#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



int parent[100];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void Union(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskalMST(int **cost, int V)
{
    int i, j;
    int edges = 0;
    int mincost = 0;

    // Initialize parent array
    for(i = 0; i < V; i++)
        parent[i] = i;

    while(edges < V - 1)
    {
        int min = INT_MAX;
        int a = -1, b = -1;

        // Find minimum edge (upper triangular only)
        for(i = 0; i < V; i++)
        {
            for(j = i + 1; j < V; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        if(u != v)
        {
            Union(u, v);
            printf("Edge %d:(%d, %d) cost:%d\n", edges, a, b, min);
            mincost += min;
            edges++;
        }

        // Mark edge as used
        cost[a][b] = INT_MAX;
        cost[b][a] = INT_MAX;
    }

    printf("Minimum cost= %d\n", mincost);
}
	



int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
