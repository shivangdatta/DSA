#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// incorrect code do again !!!!!

template <typename T>
class Graph{
    map <T , list <T>> adjList;
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
    
    void dfs_helper(T src ,map <T , bool > &visited , list <T> &order  ){
        visited[src] = true;

        for(auto it : adjList[src]){
            if(!visited[it]){
                dfs_helper(it , visited , order);
            }
        }

        order.push_front(src);
    }

    void topologicalsort_dfs(){
        map <T , bool> visited;
        list <T> order;
        for(auto it:adjList){
            T node = it.first;
            if(!visited[node]){
                dfs_helper(node , visited , order);
            }
        }
        for(auto it= order.begin() ; it!=order.end() ; it++){
            cout << *it << "->";
        }
    } 

   void topologicalsort_bfs() {
    map<T, int> indegree;
    queue <T> neighbours;

    for (auto it : adjList) {
        indegree[it.first] = 0;
    }

    // Initializing indegrees
    for (auto it : adjList) {
        for (auto it2 : it.second) {
            indegree[it2]++;
        }
    }

    for (auto it : adjList) {
        if (indegree[it.first] == 0) {
            neighbours.push(it.first);
        }
    }

    while (!neighbours.empty()) {
        T node = neighbours.front();
        neighbours.pop();
        cout << node << "-->";
        for (auto it : adjList[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                neighbours.push(it);
            }
        }
    }
}

};
int main (){
    Graph <string> g;
    g.addEdge("English", "logic");
    g.addEdge("Maths","logic");
    g.addEdge("logic","html");
    g.addEdge("logic","python");
    g.addEdge("logic","java");
    g.addEdge("logic","js");
    g.addEdge("python","webdev");
    g.addEdge("html","css");
    g.addEdge("css","js");
    g.addEdge("js","webdev");
    g.addEdge("java","webdev");
    g.addEdge("python","webdev");

    g.topologicalsort_dfs();
    g.topologicalsort_bfs();

    return 0;
}