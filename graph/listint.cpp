#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph{
    int v;
    list <int> *l;
public:
    Graph(int V){
        v = V;
        l = new list<int>[v];
    }
    void addedge(int u , int v , bool bidir = true){
        l[u].push_back(v);
        if(bidir) l[v].push_back(u);
    }
    void printadjlist(){
        for(int i = 0 ; i < v ; i++){
            for(int vertex:l[i]){
                cout << vertex << " " ;
            }
            cout << endl;
        }            
    }
};


int main(){
    Graph g(5);
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(4,3);
    g.addedge(1,4);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(1,3);
    g.printadjlist();
    return 0;
}