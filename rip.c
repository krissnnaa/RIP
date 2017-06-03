#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 16
 
// An edge in graph
struct edge
{
    int src;
    int dest;
    int h_num;
};
 
// A graph 

struct graph
{
    int V;  // Number of vertices
    int E; // Number of edges
 
    struct edge* e; // An array of edge
};
 
struct graph* create_graph(int V, int E)
{
    struct graph* g = (struct graph*) malloc( sizeof(struct graph) );
    g->V = V;
    g->E = E;
 
    g->e = (struct edge*) malloc( g->E * sizeof( struct edge ) );
 
    return g;
}

// To print vertex and distance
void print_vertex(int dist_mat[], int n)
{
    int i;
    printf("----From Source Vertex A To Following Vertex....\n");
    printf("Vertex \t\t Distance \n");
    for (i = 0; i < n; i++)
    {
        printf("%c \t\t %d\n", i+65, dist_mat[i]);
    }
}
 
// Bellman-Ford algorithm
void BellmanFord(struct graph* g, int src)
{
    int i,j,u,v,w;
    int Ver = g->V;
    int Edg = g->E;
    int dist_mat[Ver];

    // Initialize vertices
    for (i = 0; i < Ver; i++)
    {
        dist_mat[i]   = MAX_VALUE;
    }
    
    dist_mat[src] = 0;
 
    // Relax all edges
    for (i = 1; i <= Ver-1; i++)
    {
        for (j = 0; j < Edg; j++)
        {
             u = g->e[j].src;
             v = g->e[j].dest;
             w = g->e[j].cost;
            if (dist_mat[u] != MAX_VALUE && dist_mat[u] + w < dist_mat[v])
            {	
		dist_mat[v] = dist_mat[u] + w;
            }

    	}
    }	
 
   
    print_vertex(dist_mat, Ver);
 
}
 
 
void main()
{
    int i,j,a,b,c,src=0;    
    int V = 10;  // Number of vertices in graph
    int E = 10; // Number of edges in graph

    struct graph* g = create_graph(V, E);

 for(i = 0,j=0; i<V; i++)
 {
  printf("Enter the record for vertex %c \n", i+65);
  for(j=0;j<E;j=j+2)
  {
  printf("(%c : %c) :: Source Vertex value\t Destination Vertex Value\t Distance Cost\n", i+65, j+65);
  scanf("%d%d%d", &a,&b,&c);
  g->e[j].src = a;
  g->e[j].dest = b;
  g->e[j].h_num = c;
  }
 }
 
 
 BellmanFord(g,src);
 
}
