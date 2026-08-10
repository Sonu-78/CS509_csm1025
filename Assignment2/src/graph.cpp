#include "graph.h"
#include <fstream>
#include <iostream>
using namespace std;
bool readWeightedCSR( const string& filename, WeightedCSR& graph, int& source)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Could not open file: "
             << filename << endl;
        return false;
    }
    int V, E;
    if (!(file >> V >> E))
    {
        cout << "Error: Invalid graph header." << endl;
        return false;
    }

    graph.V = V;
    graph.E = E;

    graph.row_ptr.clear();
    graph.col_idx.clear();
    graph.values.clear();

    graph.row_ptr.resize(V + 1);

    for (int i = 0; i < V; i++)
    {
        int vertex;
        int degree;

        if (!(file >> vertex >> degree))
        {
            cout << "Error: Invalid vertex data." << endl;
            return false;
        }

        graph.row_ptr[vertex] =
            static_cast<int>(graph.col_idx.size());

        for (int j = 0; j < degree; j++)
        {
            int neighbor;
            int weight;

            if (!(file >> neighbor >> weight))
            {
                cout << "Error: Invalid edge data." << endl;
                return false;
            }

            graph.col_idx.push_back(neighbor);
            graph.values.push_back(weight);
        }
    }

    graph.row_ptr[V] =
        static_cast<int>(graph.col_idx.size());

    string sourceLabel;

    if (file >> sourceLabel)
    {
        if (sourceLabel == "SOURCE")
        {
            if (!(file >> source))
            {
                cout << "Error: Invalid source." << endl;
                return false;
            }
        }
        else
        {
            cout << "Error: Expected SOURCE." << endl;
            return false;
        }
    }
    else
    {
        cout << "Error: SOURCE missing." << endl;
        return false;
    }

    file.close();

    return true;
}