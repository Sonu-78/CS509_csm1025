#include <bits/stdc++.h>
#include "prim.h"
using namespace std;

vector<Edge> primMST(const WeightedCSR &graph,long long &totalWeight)
{
    vector<Edge> mst;

    totalWeight = 0;

    if (graph.V == 0)
        return mst;

    vector<int> visited(graph.V, 0);

    /*
        priority_queue item:
        weight, from, to
    */
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;

    /*
        Start Prim from vertex 0.
    */
    visited[0] = 1;

    for (int i = graph.row_ptr[0];
         i < graph.row_ptr[1];
         i++)
    {
        int v = graph.col_idx[i];
        int w = graph.values[i];

        pq.push({w, 0, v});
    }

    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();

        int weight = get<0>(current);
        int u = get<1>(current);
        int v = get<2>(current);

        if (visited[v])
            continue;

        visited[v] = 1;

        Edge edge;

        edge.u = u;
        edge.v = v;
        edge.weight = weight;

        mst.push_back(edge);
        totalWeight += weight;

        for (int i = graph.row_ptr[v];
             i < graph.row_ptr[v + 1];
             i++)
        {
            int next = graph.col_idx[i];
            int nextWeight = graph.values[i];

            if (!visited[next])
            {
                pq.push({nextWeight, v, next});
            }
        }

        if ((int)mst.size() == graph.V - 1)
            break;
    }

    return mst;
}
