#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// question 1 , find shortest path in a undiricted uniform cost graph
// question 2 , snakes and ladder problem. directed uniform cost graph


template <typename T>
class Graph {
    map <T , list <T>> adjList;
public:
    void addEdge(T u , T v , bool bidir = true){
        adjList[u].push_back(v);
        if(bidir)adjList[v].push_back(u);
    }
    void print(){
        cout << "This is the adjecency list : " << endl;
        for(auto it: adjList){
            cout << it.first << "-->" ;
            for(auto it2:it.second ){
                cout << it2 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void bfs(T src){
        cout  << "starting bfs from : " << src << endl;
        map <T , bool> visited;
        queue <T> neighbours;

        visited[src] = true;
        neighbours.push(src);

        while(!neighbours.empty()){
            T node = neighbours.front();
            neighbours.pop();
            for(auto it : adjList[node]){
                if(!visited[it]){
                    neighbours.push(it);
                    visited[it] = true;
                    cout << it << " ";
                }
            }
        }
        cout << endl;
    }
    // function to calculate shortest path , we will use a distance map instead of visited to store distance . Furthermore need to mantain a parent array if we want exact path
    void distcalc(T src){
        cout << "calculating distance from node " << src << endl ;
        map <T , int> dist;
        queue <T> neighbours;
        map <T , T> parent;
        for(auto it:adjList){
            dist[it.first] = INT_MAX;
        }
        dist[src] = 0;
        neighbours.push(src);
        parent[src] = src;
        while(!neighbours.empty()){
            T node = neighbours.front();
            neighbours.pop();
            for(auto it : adjList[node]){
                if(dist[it]==INT_MAX){
                    dist[it] = dist[node] + 1;
                    neighbours.push(it);
                    parent[it] = node;
                }
            }    
            
        }    
        for(auto it : dist){
            cout << it.first << "--> " << it.second << endl;
        }
        cout << "Distance for each is : " << endl;
        for(auto it:parent){
            cout << it.second << "-- ";
        }
        cout << endl;
    }
    void sandl(T src , T dest){
        queue <T> neighbours;
        map <T , int> rolls;
        map <T , T> parent;

        for(auto it : adjList){
            rolls[it.first] = INT_MAX;
        }

        neighbours.push(src);
        rolls[src] = 0;
        
        while(!neighbours.empty()){
            
            T node = neighbours.front();
            neighbours.pop();

            for(auto it : adjList[node]){
                if(rolls[it]==INT_MAX){
                    rolls[it] = rolls[node] + 1;
                    parent[it] = node;
                    neighbours.push(it);
                }
            }
        } 
        cout << "Path of player is : ";
        T tracer = dest;
        while(tracer != src){
            cout << tracer  << "<--" ;
            tracer = parent[tracer];
        }
        cout << tracer ;
        cout << endl;
        cout << "It will take him dice throws : ";
        cout << rolls[dest] << endl;
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
    g.bfs(0);
    g.distcalc(0);

    // given a board with positions of all jumps that is 
    int board[37] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[32] = -2;
    board[34] = -22;

    Graph <int> snakes;
    for(int i = 0 ; i <= 36 ; i++ ){
        for(int dice = 1 ; dice <= 6 ; dice++){
            int v = i + dice + board[i+dice];
            snakes.addEdge(i , v , false);
        }
    }
    snakes.sandl(0 , 36);
    
    return 0;
}