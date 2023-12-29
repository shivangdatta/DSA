#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Graph{
    map <T , list<pair <T , int>>> adjList;
public:
    void addEdge(T u , T v , int dist , bool bidir = true){
        adjList[u].push_back(make_pair(v , dist));
        if(bidir) adjList[v].push_back(make_pair(u , dist));
    }
    void print(){
        for(auto it : adjList){
            cout << it.first << "-> " ;
            for(auto it : it.second){
                cout << "( " << it.first << " , "  << it.second << " )" << " ";
            }
            cout << endl;
        }
    }

    void dijsktra(T src){
        map <T , int> dist;
        set <pair <int , T>> s;
        // setting initial dist to all infinity 
        for(auto it : adjList){
            dist[it.first] = INT_MAX;
        }
        // set src distance to 0 also insert into set
        dist[src] = 0;
        s.insert(make_pair(dist[src] , src));

        while(!s.empty()){

            auto p = *(s.begin());
            T node = p.second;
            int parent_dist = p.first;
            s.erase(s.begin());

            for(auto it : adjList[node]){
                int edge_dist = it.second;
                T dest = it.first;
                if(parent_dist + edge_dist < dist[dest]){
                    auto ptr = s.find(make_pair(dist[dest] , dest));
                    if(ptr!=s.end()){
                        s.erase(ptr);
                    }
                    // inserting the minimum values from all the neighbours
                    dist[dest] = parent_dist + edge_dist;
                    s.insert(make_pair(dist[dest] , dest));
                }
            }
        }

        // printing all the nodes 
        for(auto it : dist){
            cout << it.first << "at a distance of : " << it.second << endl;
        }
        // we can also find path by simply mantaining a parent <T,T> map
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
    india.dijsktra("Amritsar");

    return 0;
}