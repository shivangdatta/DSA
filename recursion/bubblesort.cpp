#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void bubblesort(int *arr, int size){
    if(size==1){
        return;
    }
    for(int i=0 ; i<size-1 ; i++){
        if(arr[i]<arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubblesort(arr,size-1);
}

void trurecbub(int *arr, int j, int size){
    // base case
    if(size==1){
        return;
    }
    if(j==size-1){
        j=0;
        return trurecbub(arr,j,size-1);
    }
    if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
    }
    trurecbub(arr, j+1, size);
    return;
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    int stor=size;
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];
    }
    // for(int i=0 ; i<size ; size--){
    //     for(int j=1; j<size ;j++){
    //         if(arr[i]<arr[j]){
    //             arr[i]=arr[i]^arr[j];
    //             arr[j]=arr[i]^arr[j];
    //             arr[i]=arr[i]^arr[j];
    //         }
    //         i++;
    //     }
    //     i=i-size+1;
    // }
    // bubblesort(arr,size);
    trurecbub(arr, 0 ,size);
    for(int i=0 ; i<stor ;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}