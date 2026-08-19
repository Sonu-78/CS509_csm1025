#include <bits/stdc++.h>
#include "graph.h"
#include "kruskal.h"
#include "prim.h"
using namespace std;

void printMST(const string &name, const vector<Edge> &mst,long long totalWeight,  double timeMs,int V)
{
    cout << "\n========================================" << endl;
    cout << name << endl;
    cout << "========================================" << endl;
    cout << "MST edges  : " << mst.size() << endl;
    cout << "MST weight : " << totalWeight << endl;
    cout << "Time       : " << fixed << setprecision(6)
         << timeMs << " ms" << endl;

    if ((int)mst.size() == V - 1)
        cout << "Status     : PASS" << endl;
    else
        cout << "Status     : FAIL / DISCONNECTED GRAPH" << endl;

    if (V <= 100)
    {
        cout << "Edges:" << endl;
        for (int i = 0; i < (int)mst.size(); i++)
            cout << mst[i].u << " - " << mst[i].v
                 << "  weight = " << mst[i].weight << endl;
    }
}

void runKruskal(const WeightedCSR &graph)
{
    long long totalWeight;

    auto start = chrono::high_resolution_clock::now();
    vector<Edge> mst = kruskalMST(graph, totalWeight);
    auto finish = chrono::high_resolution_clock::now();

    double timeMs = chrono::duration<double, milli>(finish - start).count();

    printMST("KRUSKAL", mst, totalWeight, timeMs, graph.V);
}

void runPrim(const WeightedCSR &graph)
{
    long long totalWeight;

    auto start = chrono::high_resolution_clock::now();
    vector<Edge> mst = primMST(graph, totalWeight);
    auto finish = chrono::high_resolution_clock::now();

    double timeMs = chrono::duration<double, milli>(finish - start).count();

    printMST("PRIM", mst, totalWeight, timeMs, graph.V);
}

void runBoth(const WeightedCSR &graph)
{
    long long kruskalWeight, primWeight;
    vector<Edge> kruskal, prim;
    double kruskalTime, primTime;

    auto startK = chrono::high_resolution_clock::now();
    kruskal = kruskalMST(graph, kruskalWeight);
    auto finishK = chrono::high_resolution_clock::now();
    kruskalTime = chrono::duration<double, milli>(finishK - startK).count();

    auto startP = chrono::high_resolution_clock::now();
    prim = primMST(graph, primWeight);
    auto finishP = chrono::high_resolution_clock::now();
    primTime = chrono::duration<double, milli>(finishP - startP).count();

    printMST("KRUSKAL", kruskal, kruskalWeight, kruskalTime, graph.V);
    printMST("PRIM", prim, primWeight, primTime, graph.V);

    cout << "\n========================================" << endl;
    cout << "COMPARISON" << endl;
    cout << "========================================" << endl;
    cout << "Kruskal weight : " << kruskalWeight << endl;
    cout << "Prim weight    : " << primWeight << endl;
    cout << "Kruskal time   : " << fixed << setprecision(6)
         << kruskalTime << " ms" << endl;
    cout << "Prim time      : " << fixed << setprecision(6)
         << primTime << " ms" << endl;

    if (kruskalWeight == primWeight &&
        kruskal.size() == prim.size() &&
        kruskal.size() == (size_t)(graph.V - 1))
        cout << "Result         : MATCH" << endl;
    else
        cout << "Result         : CHECK GRAPH / RESULTS" << endl;
}

void printUsage(const char *program)
{
    cout << "Usage:" << endl;
    cout << "  " << program << " <kruskal|prim|both> <input-file>" << endl;
    cout << "  " << program << "                  (menu mode)" << endl;
}

bool validAlgorithm(const string &algorithm)
{
    return algorithm == "kruskal" ||
           algorithm == "prim" ||
           algorithm == "both";
}

int main(int argc, char *argv[])
{
    cout << "========================================" << endl;
    cout << " CS509 Assignment 3 - MST" << endl;
    cout << " Kruskal + Prim + Previous CSR" << endl;
    cout << "========================================" << endl;

    string algorithm;
    string filename;

    // Terminal-argument mode: compatible with a common wrapper/driver.
    if (argc == 3)
    {
        algorithm = argv[1];
        filename = argv[2];
    }
    else if (argc == 1)
    {
        // Menu mode.
        cout << "\nSelect algorithm:" << endl;
        cout << "1. Kruskal" << endl;
        cout << "2. Prim" << endl;
        cout << "3. Both (comparison)" << endl;
        cout << "Choice: ";

        int choice;
        if (!(cin >> choice) || choice < 1 || choice > 3)
        {
            cout << "ERROR: Invalid algorithm selection." << endl;
            return 1;
        }

        if (choice == 1) algorithm = "kruskal";
        if (choice == 2) algorithm = "prim";
        if (choice == 3) algorithm = "both";

        cout << "Input file: ";
        cin >> filename;
    }
    else
    {
        printUsage(argv[0]);
        return 1;
    }

    if (!validAlgorithm(algorithm))
    {
        cout << "ERROR: Invalid algorithm selection. Use kruskal, prim, or both." << endl;
        return 1;
    }

    WeightedCSR graph;
    int source = 0;

    // readWeightedCSR internally reads adjacency-list input and calls
    // convertToCSR(), reusing the previous assignment's CSR approach.
    if (!readWeightedCSR(filename, graph, source))
    {
        cout << "ERROR: Input file validation failed." << endl;
        return 1;
    }

    cout << "\nGraph loaded successfully." << endl;
    cout << "Vertices : " << graph.V << endl;
    cout << "Edges    : " << graph.E << endl;
    cout << "CSR size : " << graph.col_idx.size() << endl;

    if (algorithm == "kruskal")
        runKruskal(graph);
    else if (algorithm == "prim")
        runPrim(graph);
    else
        runBoth(graph);

    cout << "\nProgram completed successfully." << endl;
    return 0;
}
