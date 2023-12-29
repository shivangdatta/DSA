// merge k sorted arrays 

#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;


int main(){
    int size;
    cin>>size;
    int row_size;
    int **arr;
    arr = (int **)malloc(size);
    for(int i = 0 ; i<size ; i++){
        cin>>row_size;
        arr[i] = (int *)malloc(row_size);
    }

    for(int i = 0 ; i<size ; i++){
        for(int j = 0 ; j<sizeof(arr[i])/sizeof(int) ; j++){
            cin>>arr[i][j];
        }
    }

    priority_queue <int , vector<int> , greater<int>> pq_min;
    
    return 0;
}