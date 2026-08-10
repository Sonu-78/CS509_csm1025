#include<bits/stdc++.h>
#include"bellman_ford.h"
#include<climits>
bool bellmanFord( 
    const WeightedCSR& graph,
    int source,
    std::vector<long long>&dist

)
{
    dist.assign(graph.V,LLONG_MAX);
    dist[source]=0;
    for(int i=0;i<graph.V-1;i++){
        bool changed=false;
        for(int u=0;u<graph.V;u++){
            if(dist[u]==LLONG_MAX)
            continue;
            for(int j=graph.row_ptr[u]; j<graph.row_ptr[u+1];j++){
                int v=graph.col_idx[j];
                int weight=graph.values[j];
                if(dist[u]+weight<dist[v]){
                    dist[v]=dist[u]+weight;
                    changed=true;
                }
            }
      
      
        }
         if(!changed){
            break;
         }



    }


    for(int u=0;u<graph.V;u++){
        if(dist[u]==LLONG_MAX){
            continue;
        }
        for(int j=graph.row_ptr[u];j<graph.row_ptr[u+1];j++){
            int v=graph.col_idx[j];
            int weight=graph.values[j];
            if(dist[u]+weight<dist[v]){
                return false;
            }
        }
    }

    return true;
}