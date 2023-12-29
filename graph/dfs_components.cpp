//using dfs traversal for components which may or may not be conncected also count differenct components

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


template <typename T>
class Graph{
    map <T , list<T>> adjList;
public:
    void addEdge(T u , T v , bool bidir = true){
        adjList[u].push_back(v);
        if(bidir) adjList[v].push_back(u);
    }
    void print(){
        for(auto it:adjList){
            cout << it.first << "<--";
            for(auto it2:it){
                cout << *it2 << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(T src , map <T , bool> &visited){
        visited[src] = true;
        cout << src << " ";
        for(auto it:adjList[src]){
            if(!visited[it]){
                dfsHelper(it , visited);
            }
        }
    }

    void dfs_components(T src){
        int no_components = 1;
        map <T , bool> visited;        
        dfsHelper(src , visited);
        cout << endl;
        for(auto it:adjList){
            if(!visited[it.first]){
                no_components++;
                dfsHelper(it.first , visited);
                cout << endl;
            }
        }
        cout << "The graph has these many components " << no_components << endl;
    }
};

int main(){
    Graph <string> g;
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Delhi","Jaipur");
    g.addEdge("Mumbai","Jaipur");
    g.addEdge("Mumbai","Bhopal");
    g.addEdge("Delhi","Bhopal");
    g.addEdge("Mumbai","Bangalore");
    g.addEdge("Agra","Delhi");
    g.addEdge("Andaman","Nicobar");

    g.dfs_components("Amritsar");
    return 0;
}