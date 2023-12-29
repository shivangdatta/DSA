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

    bool cycle_detect(T src){
        map <T , bool> visited;
        map <T , T> parent;

        for(auto it:adjList){
            visited[it.first] = true; 
        }
        visited[src] = true;
        parent[src] = src;

        for(auto it : adjList){

            for(auto it2 : it.second){
                if(!visited[it2]){
                    visited[it2]=true; 
                    parent[it2]=it.first;
                }
                else{
                    if(it2!=parent[it.first])return true;
                }
            }
        }    
        return false;
    }

    bool dfs_helper(T src , map <T , bool> &visited , map <T , bool> &instack){
        visited[src] = true;
        instack[src] = true;


        // try to hande 3 case where value of instack  and visited is (false , false) || (false , true) || (true , true) 
        for(auto it:adjList[src]){
            if((!visited[it] && dfs_helper(it , visited , instack)) || instack[it]){
                return true;
            }
        }

        instack[src] = false;
        return false;
    }

    bool cycle_detect_dfs(){
        map <T , bool> visited;
        map <T , bool> instack;

        for(auto it : adjList ){
            T node = it.first;
            if(!visited[node]){
                bool check = dfs_helper(node , visited , instack);
                if(check) return true;
            }
        }
        return false;
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

    if(g.cycle_detect(0)) cout << "yes" << endl;
    else cout << "No" << endl;
    
    Graph <int> g2;
    g2.addEdge( 0, 2, false);
    g2.addEdge( 0, 1, false);
    g2.addEdge( 2, 3, false);
    g2.addEdge( 2, 4, false);
    g2.addEdge( 3, 0, false);
    g2.addEdge( 4, 5, false);
    g2.addEdge( 1, 5, false);

    if(g2.cycle_detect_dfs()) cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;
}