#include <iostream>
#include <utility>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int binsearch(int *arr,int size,int num){
    int beg=0,end=size-1;
    int mid;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]>num){
            end=mid-1;
        }
        else if(arr[mid]<num){
            beg=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int firstbinsearch(int *arr, int size, int key){
    int beg=0 , end=size-1;
    int mid,ans=-1;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]>key){
            beg=mid+1;
        }
        else if(arr[mid]<key){
            end=mid-1;
        }
        else{
            ans=mid;
            end=mid-1;
        }
    }
    return ans;
}

int lastbinsearch(int *arr, int size , int key){
    int beg=0, end=size-1;
    int mid, ans=-1;
    while(beg<= end){
        mid=(beg+end)/2;
        if(arr[mid]<key){
            beg=mid+1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            ans=mid;
            beg=mid+1;
        }
    }
    return ans;
}

int main(){
    int size ;
    cin>>size;
    int *arr;
    arr=(int*)malloc(sizeof(int)*size);
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];
    }
    int search,pos;
    cin>>search;
    sort(arr, arr+size);
    // pos=firstbinsearch(arr,size,search);
    pos=lastbinsearch(arr,size,search);
    cout<<"found at position : "<<pos<<endl;
}