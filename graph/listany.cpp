#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <list>

using namespace std;

template <typename T>
class Graph{
    map <T, list<T> > adjlist;
public:
    Graph(void){}
    void addEdge(T u , T v , bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir)adjlist[v].push_back(u);
    }
    void print(){
        for(auto it= adjlist.begin() ; it!=adjlist.end() ;it++){
            cout << it->first << " -> ";
            for(auto it2=it->second.begin() ; it2!=it->second.end() ; it2++){
                cout << *it2 << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph <string>g;
    g.addEdge("modi" , "trump");
    g.addEdge("modi" , "biden");
    g.addEdge("modi" , "obama");
    g.addEdge("obama" , "biden");
    g.addEdge("putin" , "biden");
    g.addEdge("putin" , "obama");

    g.print();
    return 0;
}