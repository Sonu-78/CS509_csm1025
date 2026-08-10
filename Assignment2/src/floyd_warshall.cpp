#include<bits/stdc++.h>
#include "floyd_warshall.h"
#include "graph.h"
#include "bellman_ford.h"
using namespace std;
bool floydWarshall(const WeightedCSR& graph,vector<vector<long long>>&dist){
    int V=graph.V;
    dist.assign(V,vector<long long>(V,LLONG_MAX));
    for(int i=0;i<V;i++){
        dist[i][i]=0;
    }
    for(int u=0;u<V;u++){
        for(int j=graph.row_ptr[u];j<graph.row_ptr[u+1];j++){
            int v=graph.col_idx[j];
            int weight=graph.values[j];
            if(weight<dist[u][v]){
                dist[u][v]=weight;
            }
        }
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            if(dist[i][k]==LLONG_MAX)
            continue;
            for(int j=0;j<V;j++){
                if(dist[k][j]==LLONG_MAX)
                continue;
                 long long newDistance=dist[i][k]+dist[k][j];
                 if(newDistance<dist[i][j]){
                    dist[i][j]=newDistance;
                 }
            
               
            }

           
        }
    }

   for(int i=0;i<V;i++){
    if(dist[i][i] <0){
        return false;
    }
   }
   return true;


}
