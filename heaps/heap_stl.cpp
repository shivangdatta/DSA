#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    priority_queue <int> pq_max;
    priority_queue <int , vector <int> , greater<int>> pq_min;
    int arr[6]={1,2,3,4,5,6};
    for(int i = 0 ; i < 6 ; i++){
        pq_min.push(arr[i]);
    }
    for(int i = 0 ; i < 6 ; i++){
        pq_max.push(arr[i]);
    }
    while(!pq_max.empty()){
        cout<<pq_max.top()<<" ";
        pq_max.pop();
    }
    cout<<endl;
    while(!pq_min.empty()){
        cout<<pq_min.top()<<" ";
        pq_min.pop();
    }
    cout<<endl;
    return 0;
}