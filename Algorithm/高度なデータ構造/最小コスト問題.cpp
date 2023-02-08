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
    Edge(int arg_to, int arg_capacity, int arg_cost, int arg_rev_index) {
        to = arg_to;
        capacity = arg_capacity;
        cost = arg_cost;
        rev_index = arg_rev_index;
    }

    int to, capacity, cost, rev_index;
};

int V;
vector<Edge> G[NUM];
int dist[NUM];
int pre_node[NUM], pre_edge[NUM];

void add_edge(int from, int to, int capacity, int cost) {
    G[from].push_back(Edge(to, capacity, cost, G[to].size()));
    G[to].push_back(Edge(from, 0, -cost, G[from].size() - 1));
}

int min_cost_flow(int source, int sink, int flow) {
    int ret = 0;
    while (flow > 0) {
        for (int i = 0; i < V; i++) dist[i] = BIG_NUM;
        dist[source] = 0;
        bool update = true;
        while (update) {
            update = false;
            for (int node_id = 0; node_id < V; node_id++) {
                if (dist[node_id] == BIG_NUM) continue;
                for (int i = 0; i < G[node_id].size(); i++) {
                    Edge &e = G[node_id][i];
                    if (e.capacity > 0 && dist[e.to] > dist[node_id] + e.cost) {
                        dist[e.to] = dist[node_id] + e.cost;
                        pre_node[e.to] = node_id;
                        pre_edge[e.to] = i;
                        update = true;
                    }
                }
            }
        }

        if (dist[sink] == BIG_NUM) {
            return -1;
        }

        int tmp_flow = flow;
        for (int node_id = sink; node_id != source;
             node_id = pre_node[node_id]) {
            tmp_flow =
                min(tmp_flow, G[pre_node[node_id]][pre_edge[node_id]].capacity);
        }
        flow -= tmp_flow;
        ret += tmp_flow * dist[sink];
        for (int node_id = sink; node_id != source;
             node_id = pre_node[node_id]) {
            Edge &e = G[pre_node[node_id]][pre_edge[node_id]];
            e.capacity -= tmp_flow;
            G[node_id][e.rev_index].capacity += tmp_flow;
        }
    }
    return ret;
}

int main() {
    int E, F;
    scanf("%d %d %d", &V, &E, &F);

    int from, to, capacity, cost;
    for (int loop = 0; loop < E; loop++) {
        scanf("%d %d %d %d", &from, &to, &capacity, &cost);
        add_edge(from, to, capacity, cost);
    }

    printf("%d\n", min_cost_flow(0, V - 1, F));

    return 0;
}
