#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

void merge(int *arr, int ll, int ul){
    int mid=(ll+ul)/2;
    int i=ll;
    int j=mid+1;
    int k=ll;
    int *temp;
    temp=(int *)malloc(sizeof(int)*(ul+1));
    while(i<=mid && j<=ul){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=ul){
        temp[k++]=arr[j++];
    }

    for(int m=ll ; m<=ul; m++){
        arr[m]=temp[m];
    }
}
void mergesort(int *arr, int ll, int ul){
    int mid=(ll+ul)/2;
    if(ll>=ul){
        return;
    }
    mergesort(arr,ll,mid);
    mergesort(arr,mid+1,ul);
    merge(arr,ll,ul);
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];
    }
    int ul=size-1;
    mergesort(arr,0,ul);
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}