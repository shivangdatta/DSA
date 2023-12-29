#include <iostream>
#include <stdio.h>

using namespace std;

int binsearch(int *arr, int ll , int ul , int key){
    int mid=(ll+ul)/2;
    if(ll>ul){
        return -1;
    }
    if(arr[mid]>key){
        ul=mid-1;
    }
    if(arr[mid]<key){
        ll=mid+1;
    }
    if(arr[mid]==key){
        return mid;
    }
    return binsearch(arr, ll , ul , key);
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0 ; i <size ; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"enter :";
    cin>>key;
    cout<<binsearch(arr,0,size-1,key)<<endl;
    return 0;
}