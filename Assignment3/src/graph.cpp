#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

bool readWeightedAdjList(const string &filename,
                         WeightedAdjList &graph,
                         int &source)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "ERROR: Cannot open input file: " << filename << endl;
        return false;
    }

    int V, E;

    if (!(file >> V >> E) || V <= 0 || E < 0)
    {
        cout << "ERROR: Invalid graph header. Expected: V E" << endl;
        return false;
    }

    graph.V = V;
    graph.E = E;
    graph.adj.assign(V, {});
    source = 0;

    string line;
    getline(file, line);

    vector<int> seen(V, 0);
    long long directedEntries = 0;

    for (int lineNo = 0; lineNo < V; )
    {
        if (!getline(file, line))
        {
            cout << "ERROR: Missing vertex line for vertex " << lineNo << endl;
            return false;
        }

        if (line.find_first_not_of(" \t\r\n") == string::npos)
            continue;

        stringstream ss(line);
        int vertex, degree;

        if (!(ss >> vertex >> degree))
        {
            cout << "ERROR: Invalid vertex line: " << line << endl;
            return false;
        }

        if (vertex < 0 || vertex >= V)
        {
            cout << "ERROR: Invalid vertex: " << vertex << endl;
            return false;
        }

        if (seen[vertex])
        {
            cout << "ERROR: Duplicate vertex line: " << vertex << endl;
            return false;
        }

        if (degree < 0)
        {
            cout << "ERROR: Negative degree for vertex " << vertex << endl;
            return false;
        }

        seen[vertex] = 1;

        for (int j = 0; j < degree; j++)
        {
            int neighbor, weight;

            if (!(ss >> neighbor >> weight))
            {
                cout << "ERROR: Invalid adjacency data for vertex "
                     << vertex << endl;
                return false;
            }

            if (neighbor < 0 || neighbor >= V)
            {
                cout << "ERROR: Invalid neighbor " << neighbor
                     << " for vertex " << vertex << endl;
                return false;
            }

            graph.adj[vertex].push_back({neighbor, weight});
            directedEntries++;
        }

        string extra;
        if (ss >> extra)
        {
            cout << "ERROR: Extra data on vertex line: " << line << endl;
            return false;
        }

        lineNo++;
    }

    for (int i = 0; i < V; i++)
    {
        if (!seen[i])
        {
            cout << "ERROR: Missing vertex line: " << i << endl;
            return false;
        }
    }

    // Optional SOURCE line. It is not used by MST, but is retained
    // for compatibility with the previous assignment's graph format.
    while (getline(file, line))
    {
        if (line.find_first_not_of(" \t\r\n") == string::npos)
            continue;

        string word;
        stringstream ss(line);
        ss >> word;

        if (word == "SOURCE")
        {
            if (!(ss >> source))
            {
                cout << "ERROR: Invalid SOURCE line" << endl;
                return false;
            }

            if (source < 0 || source >= V)
            {
                cout << "ERROR: Invalid source vertex: " << source << endl;
                return false;
            }
        }
    }

    // For the usual undirected input, every edge occurs twice.
    // We still validate only that the file has a sensible number of entries.
    if (directedEntries == 0 && V > 1)
    {
        cout << "ERROR: Graph contains no edges" << endl;
        return false;
    }

    return true;
}

void convertToCSR(const WeightedAdjList &adjGraph,
                  WeightedCSR &csrGraph)
{
    csrGraph.V = adjGraph.V;
    csrGraph.E = adjGraph.E;
    csrGraph.row_ptr.assign(csrGraph.V + 1, 0);
    csrGraph.col_idx.clear();
    csrGraph.values.clear();

    for (int u = 0; u < adjGraph.V; u++)
        csrGraph.row_ptr[u + 1] =
            csrGraph.row_ptr[u] + adjGraph.adj[u].size();

    int totalEntries = csrGraph.row_ptr[csrGraph.V];
    csrGraph.col_idx.reserve(totalEntries);
    csrGraph.values.reserve(totalEntries);

    for (int u = 0; u < adjGraph.V; u++)
    {
        for (int j = 0; j < (int)adjGraph.adj[u].size(); j++)
        {
            csrGraph.col_idx.push_back(adjGraph.adj[u][j].to);
            csrGraph.values.push_back(adjGraph.adj[u][j].weight);
        }
    }
}

bool readWeightedCSR(const string &filename,
                     WeightedCSR &graph,
                     int &source)
{
    WeightedAdjList adjGraph;

    if (!readWeightedAdjList(filename, adjGraph, source))
        return false;

    convertToCSR(adjGraph, graph);
    return true;
}

vector<Edge> getEdgeList(const WeightedCSR &graph)
{
    vector<Edge> edges;

    for (int u = 0; u < graph.V; u++)
    {
        for (int i = graph.row_ptr[u];
             i < graph.row_ptr[u + 1]; i++)
        {
            int v = graph.col_idx[i];
            int w = graph.values[i];

            // Assignment graph is undirected. Keep one copy of each edge.
            if (u < v)
                edges.push_back({u, v, w});
        }
    }

    return edges;
}
