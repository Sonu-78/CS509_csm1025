#include <bits/stdc++.h>
#include "kruskal.h"
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rankValue;

public:
    DSU(int n)
    {
        parent.resize(n);
        rankValue.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (rankValue[a] < rankValue[b])
            swap(a, b);

        parent[b] = a;

        if (rankValue[a] == rankValue[b])
            rankValue[a]++;

        return true;
    }
};

vector<Edge> kruskalMST(const WeightedCSR &graph,
                        long long &totalWeight)
{
    vector<Edge> edges = getEdgeList(graph);
    vector<Edge> mst;

    totalWeight = 0;

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b)
         {
             return a.weight < b.weight;
         });

    DSU dsu(graph.V);

    for (int i = 0; i < (int)edges.size(); i++)
    {
        Edge edge = edges[i];

        if (dsu.unite(edge.u, edge.v))
        {
            mst.push_back(edge);
            totalWeight += edge.weight;

            if ((int)mst.size() == graph.V - 1)
                break;
        }
    }

    return mst;
}
