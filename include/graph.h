#ifndef GRAPH_H
#define GRAPH_H
#define GRAPH_MAX 64
typedef struct { int n; int w[GRAPH_MAX][GRAPH_MAX]; } Graph;
void graph_init(Graph *g, int n);
void dijkstra(const Graph *g, int source, int dist[]);
void bellman_ford(const Graph *g, int source, int dist[], int *negative_cycle);
void floyd_warshall(const Graph *g, int dist[GRAPH_MAX][GRAPH_MAX]);
int prim_mst(const Graph *g);
int max_flow(const int cap[GRAPH_MAX][GRAPH_MAX], int n, int source, int sink);
int max_bipartite_matching(const int edges[GRAPH_MAX][GRAPH_MAX], int left, int right);
#endif
