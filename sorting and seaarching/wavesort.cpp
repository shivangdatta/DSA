#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void wavesort(int *arr, int size){
    for(int i=0 ; i<size ; i=i+2){
        if(arr[i-1] < arr[i]){
            swap(arr[i-1],arr[i]);
        }
        else if(arr[i+1] < arr[i]){
            swap(arr[i],arr[i+1]);
        }
    }
}
void display(int *arr,int size ){
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={21,4,14,55,3,0,9};
    wavesort(arr,6);
    display(arr,6);
    return 0;
}