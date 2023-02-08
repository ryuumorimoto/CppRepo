#include <stdio.h>
#include <time.h>

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

#define NUM 100

struct Edge {
    Edge(int arg_to, int arg_capacity, int arg_rev_index) {
        to = arg_to;
        capacity = arg_capacity;
        rev_index = arg_rev_index;
    }
    int to, capacity, rev_index;
};

int V, E;

vector<Edge> G[NUM];
int dist[NUM];
int cheked_index[NUM];

void add_edge(int from, int to, int capacity) {
    G[from].push_back(Edge(to, capacity, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size() - 1));
}

void bfs(int source) {
    for (int i = 0; i < V; i++) dist[i] = -1;
    queue<int> Q;
    dist[source] = 0;
    Q.push(source);

    while (!Q.empty()) {
        int node_id = Q.front();
        Q.pop();
        for (int i = 0; i < G[node_id].size(); i++) {
            Edge &e = G[node_id][i];
            if (e.capacity > 0 && dist[e.to] < 0) {
                dist[e.to] = dist[node_id] + 1;
                Q.push(e.to);
            }
        }
    }
}

int dfs(int node_id, int sink, int flow) {
    if (node_id == sink) return flow;

    for (int &i = cheked_index[node_id]; i < G[node_id].size(); i++) {
        Edge &e = G[node_id][i];
        if (e.capacity > 0 && dist[node_id] < dist[e.to]) {
            int tmp_flow = dfs(e.to, sink, min(flow, e.capacity));
            if (tmp_flow > 0) {
                e.capacity -= tmp_flow;
                G[e.to][e.rev_index].capacity += tmp_flow;
                return tmp_flow;
            }
        }
    }
    return 0;
}

int max_flow(int source, int sink) {
    int flow = 0, add;
    while (true) {
        bfs(source);
        if (dist[sink] < 0) break;
        for (int i = 0; i < V; i++) cheked_index[i] = 0;
        while ((add = dfs(source, sink, BIG_NUM)) > 0) {
            flow += add;
        }
    }
    return flow;
}

int main() {
    scanf("%d %d", &V, &E);

    int from, to, cost;

    for (int loop = 0; loop < E; loop++) {
        scanf("%d %d %d", &from, &to, &cost);
        add_edge(from, to, cost);
    }

    printf("%d\n", max_flow(0, V - 1));

    return 0;
}