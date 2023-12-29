#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Graph{
    map <T , list< pair <T , int>>> adjList;
public:
    void addEdge(T u , T v , int dist , bool bidir = true){
        adjList[u].push_back(make_pair(v , dist));
        if(bidir) adjList[v].push_back(make_pair(u , dist));
    }
    void print(){

    }
    bool neg_cycle_detect(T src){
        // detecting using bellman ford
        // first relax n-1 times then relax 1 more time to see if there are any changes in dist values
        // what is relaxation ??
        // relaxation : iterating through loop once then setting distances to minimum possible .

        map <T , int> dist;

        for(auto it : adjList){
            dist[it.first] = INFINITY;
        }
        dist[src] = 0;
        //relaxation step
        for(int i = 0 ; i < adjList.size()-1 ; i++){
            for(auto it : adjList){
                T u = it.first;
                for(auto it2 : it.second){
                    T v = it2.first;
                    int cost_u_v = it2.second;
                    if(dist[u] + cost_u_v < dist[v] && dist[u]!=INFINITY){
                        dist[v] = dist[u] + cost_u_v;
                    }
                }
            }
        }
        // relax nth time
        for(auto it : adjList){
            T u = it.first;
            for(auto it2 : it.second){
                T v = it2.first;
                int cost_u_v = it2.second;
                if(dist[u]+cost_u_v < dist[v] && dist[u]!=INFINITY){
                    return true;
                }
            }
        }
        return false;
    }
    void bellman_ford(T src){
        map <T , int> dist;

        for(auto it : adjList){
            dist[it.first] = INT_MAX;
        }
        dist[src] = 0;

        for(int i = 0 ; i < adjList.size()-1 ; i++){

            for(auto it : adjList){
                T u = it.first;
                for(auto it2 : it.second){
                    T v = it2.first;
                    int cost_u_v = it2.second;
                    if(dist[u] + cost_u_v < dist[v] && dist[u]!=INT_MAX) {
                        dist[v] = dist[u] + cost_u_v;
                    }
                }
            }
        } 

        for(auto it:dist){
            cout << it.first << "-->" << it.second << endl;
        }
    }
};

int main(){
    Graph<string> india;
    india.addEdge("Amritsar", "Delhi",1);
    india.addEdge("Amritsar", "Jaipur",4);
    india.addEdge("Jaipur", "Delhi",2);
    india.addEdge("Jaipur", "Mumbai",8);
    india.addEdge("Bhopal", "Agra",2);
    india.addEdge("Mumbai", "Bhopal",3);
    india.addEdge("Agra", "Delhi",1);
    //india.print();
    india.bellman_ford("Amritsar");
    
    if(india.neg_cycle_detect("Amritsar")) cout << "cycle" << endl;
    else cout << "no cycle" << endl;

    return 0;
}