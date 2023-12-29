#include <iostream>
#include <bits/stdc++.h>

using namespace std;


template <typename T>
class Graph{
    map <T , list<T>> adjList;
public:
    void addEdge(T u , T v , bool bidir=true){
        adjList[u].push_back(v);
        if(bidir)adjList[v].push_back(u);
    }
    void print(){
        for(auto it=adjList.begin() ; it!=adjList.end() ; it++){
            cout << it->first << "->" ;
            for(auto it2=it->second.begin() ; it2 != it->second.end() ; it2++){
                cout << *it2 << " ";
            }
            cout << endl;
        }
    }
    void bfs(T src){
        queue <T> neighbours;
        map <T , bool> visited;
        
        neighbours.push(src);
        visited[src]=true;
        cout << src << " "; 
        while(!neighbours.empty()){
            
            T node = neighbours.front();
            neighbours.pop();
            for(auto it = adjList[node].begin() ; it != adjList[node].end() ; it++){
                if(!visited[*it]){ 
                    neighbours.push(*it);
                    visited[*it]=true;
                    cout << *it << " ";
                }
            }
        }
       
    }
};

int main(){
    Graph <int>g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.print();
    g.bfs(0);
    return 0;
}