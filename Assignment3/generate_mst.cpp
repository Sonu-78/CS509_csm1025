#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    if (V <= 0)
    {
        cout << "Invalid number of vertices.\n";
        return 1;
    }

    long long maxEdges = 1LL * V * (V - 1) / 2;

    if (E < V - 1 || E > maxEdges)
    {
        cout << "Invalid number of edges.\n";
        cout << "For " << V << " vertices, E must be between "
             << V - 1 << " and " << maxEdges << ".\n";
        return 1;
    }

    string filename;

    cout << "Enter output filename: ";
    cin >> filename;

    ofstream out(filename);

    if (!out)
    {
        cout << "Cannot create file.\n";
        return 1;
    }

    mt19937 rng(time(0));
    uniform_int_distribution<int> weightDist(1, 100);

    set<pair<int, int>> edges;

    // First create a connected graph using a random spanning tree
    for (int v = 1; v < V; v++)
    {
        uniform_int_distribution<int> parentDist(0, v - 1);
        int parent = parentDist(rng);

        int weight = weightDist(rng);

        edges.insert({parent, v});

        out << parent << " " << v << " " << weight << "\n";
    }

    // Add remaining random edges
    while ((int)edges.size() < E)
    {
        uniform_int_distribution<int> vertexDist(0, V - 1);

        int u = vertexDist(rng);
        int v = vertexDist(rng);

        if (u == v)
            continue;

        if (u > v)
            swap(u, v);

        if (edges.count({u, v}))
            continue;

        edges.insert({u, v});

        int weight = weightDist(rng);

        out << u << " " << v << " " << weight << "\n";
    }

    out.close();

    cout << "\nGraph generated successfully!\n";
    cout << "Vertices : " << V << "\n";
    cout << "Edges    : " << E << "\n";
    cout << "File     : " << filename << "\n";

    return 0;
}