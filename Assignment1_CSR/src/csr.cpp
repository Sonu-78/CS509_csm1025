#include "../include/csr.h"
#include <fstream>
void CSR::readGraph(const string &file) {
    ifstream fin(file);

    if (!fin) {
        cout << "Error: Cannot open " << file << endl;
        return;
    }

    fin >> V >> E;

    if (!fin) {
        cout << "Error: Empty or invalid input file." << endl;
        return;
    }

    adj.resize(V);

    for (int i = 0; i < V; i++) {
        int u, deg;
        fin >> u >> deg;
       while (deg--) {
    int v, w;
    fin >> v >> w;

    adj[u].push_back(v);
    values.push_back(w);
}
       
    }

    fin.close();
}


void CSR::convertToCSR() {
    row_ptr.push_back(0);

    for (int i = 0; i < V; i++) {
        for (int v : adj[i])
            col_idx.push_back(v);

        row_ptr.push_back(col_idx.size());
    }
}
void CSR::printCSR() {

    cout << "\nrow_ptr:\n";
    for (int x : row_ptr)
        cout << x << " ";

    cout << "\n\ncol_idx:\n";
    for (int x : col_idx)
        cout << x << " ";

    cout << "\n\nvalues:\n";
    for (int x : values)
        cout << x << " ";

    cout << endl;
}
