#include <iostream>
#include <stdio.h>

using namespace std;

int pivandsep(int *arr, int ll, int ul){
    int pivot=arr[ul];
    int i=ll-1;
    int j=ll;
    for(j=ll ; j<=ul-1 ; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[ul],arr[i+1]);
    return i+1;
}

void quicksort(int *arr, int ll , int ul){
    int p;
    if(ll>=ul){
        return;
    }
    p=pivandsep(arr,ll,ul);
    quicksort(arr,ll,p-1);
    quicksort(arr,p+1,ul); 
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];
    }
    quicksort(arr,0,size-1);
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    return 0; 
}
