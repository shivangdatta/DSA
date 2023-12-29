// find k cars with min dist

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class car{
    public:
        int x;
        int y;
        int id;
        car(int x , int y , int name){
            this->x = x;
            this->y = y;
            id = name;
        }   
        int dist(){
            return x*x + y*y;
        }
};


// functor
class mycomp{
    public:
        bool operator()(car a , car b){
            return a.dist() < b.dist();
        }
};


int main(){
    
    priority_queue <car , vector <car> , mycomp> pq_min;
    int x[5];
    int y[5];
    for(int i=0 ; i<5 ; i++){
        cin>>x[i]>>y[i];
    }
    
    return 0;
}