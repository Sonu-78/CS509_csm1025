#include<bits/stdc++.h>

#include "graph.h"
#include "bellman_ford.h"
#include "floyd_warshall.h"
using namespace std;
int main(){
    cout<<"====Assignment 2===="<<endl;
    vector<string>testFiles={
        "tests/bf_10.txt",
        "tests/bf_100.txt",
        "tests/bf_10000.txt",
        "tests/bf_50000.txt",
        "tests/bf_100000.txt"
    };
    for(const string& filename : testFiles){
        cout<<endl;
        cout<<"================================================================================="<<endl;
        cout<<"Reading: "<<filename<<endl;
    
    WeightedCSR graph;
    int source;
    bool loaded =readWeightedCSR(filename,graph,source);
    if(!loaded){
        cout<<"Failed to read graph"<<endl;
        continue;
    }

cout << "Graph loaded successfully" << endl;
cout << "Vertices " << graph.V << endl;
cout << "Edges " << graph.E << endl;
cout << "source " << source << endl;
   //printGraphInfo(filename,graph,source);
    vector<long long>dist;
     auto start=chrono::high_resolution_clock::now();
bool noNegativeCycle= bellmanFord(graph, source, dist);
auto end =chrono::high_resolution_clock::now();
double time_ms =chrono::duration<double, std::milli>(end - start).count();
    cout<<" Algorithm: Bellman_Ford"<<endl;
    cout<<"Source:"<<source<<endl;
    cout<<"Time: "<<time_ms<<" ms "<<endl;
    if(!noNegativeCycle){
        cout<<"Negative cycle:true"<<endl;
        continue;}
         cout<<"Negative cycle:none"<<endl;
         if(graph.V<=100)
         {  

             cout<<"Vertex Distance"<<endl;
              for(int v=0;v<graph.V;v++){
            cout<<v<<" ";
            if(dist[v]==LLONG_MAX)
            {
                cout<<"INF";
            }
            else{
                cout<<dist[v];
               
            }
             cout<<endl;
        }
       // printDistances(dist);

    }

    }   
       // cout<<"Negative cycle:none"<<endl;
         cout << endl;
    cout << "=================================================================================" << endl;
    cout << "Floyd-Warshall" << endl;

    vector<string> fwTestFiles = {
    "tests/floyd_warshall/fw_10.txt",
    "tests/floyd_warshall/fw_100.txt",
    "tests/floyd_warshall/fw_500.txt",
    "tests/floyd_warshall/fw_1000.txt",
    "tests/floyd_warshall/fw_2000.txt"
};
    for (const string& fwFile : fwTestFiles){
    
    WeightedCSR fwGraph;
    int fwSource;

    bool fwFileLoaded = readWeightedCSR(
        fwFile,
        fwGraph,
        fwSource
    );

    if (!fwFileLoaded)
    {
        cout << "Failed to read graph for Floyd-Warshall" << endl;
    }
    else
    {
        vector<vector<long long>> fwDist;

        auto fwStart =
            chrono::high_resolution_clock::now();

        bool fwNoNegativeCycle =
            floydWarshall(fwGraph, fwDist);

        auto fwEnd =
            chrono::high_resolution_clock::now();

        double fwTime =
            chrono::duration<double, milli>(
                fwEnd - fwStart
            ).count();

        cout << "Reading: " << fwFile << endl;
        cout << "Graph loaded successfully" << endl;
        cout << "Vertices " << fwGraph.V << endl;
        cout << "Edges " << fwGraph.E << endl;

        cout << "Algorithm: Floyd-Warshall" << endl;
        cout << "Time: " << fwTime << " ms" << endl;

        if (!fwNoNegativeCycle)
        {
            cout << "Negative cycle: true" << endl;
        }
        else
        {
            cout << "Negative cycle: none" << endl;
            if(fwGraph.V<=50){

           cout << "Distance Matrix" << endl;

            for (int i = 0; i < fwGraph.V; i++)
            {
                for (int j = 0; j < fwGraph.V; j++)
                {
                    if (fwDist[i][j] == LLONG_MAX)
                    {
                        cout << "INF ";
                    }
                    else
                    {
                        cout << fwDist[i][j] << " ";
                    }
                }

                cout << endl;
            } 
            //printDistancesMatrix(fwDist);



        }
      }
    }
}








    
    return 0;
}