#include <iostream>
#include <bits/stdc++.h>

using namespace std;


template <typename T>
class Graph{
    map <T , list <T>> adjList;
public:
    void addEdge(T u , T v , bool bidir = true){
        adjList[u].push_back(v);
        if(bidir) adjList[v].push_back(u);
    }
    void print(){
        for(auto it : adjList){
            cout << it.first << "--> "; 
            for(auto it1 : it.second){
                cout << it1 << " ";
            }
            cout << endl;
        }
    }
    void dfsHelper(T src , map <T , bool> &visited){

        visited[src] = true;
        cout << src << " ";

        for(auto it : adjList[src]){
            if(!visited[it]){

                dfsHelper(it , visited);
            }
        }
    }
    void dfs(T src){
        map <T , bool > visited;
        dfsHelper( src , visited);
    }
};


int main(){
    Graph <int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(1,3);
    g.print();
    g.dfs(0);
    return 0;
}