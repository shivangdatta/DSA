#include <iostream>
#include <stdio.h>

using namespace std;

bool linsearch(int *arr, int size , int key){
    if(arr[0]==key){
        return true;
    }
    if(size==1){
        return false;   
    }
    linsearch(arr+1,size-1,key);

}

int poslinsearch(int *arr, int size, int key){
    int pos=1;
    if(arr[0]==key){
        return 1;
    }
    // if(size==1){
    //     return 9;
    // }
    return pos+=poslinsearch(arr+1,size-1,key);
}

int bettlin(int *arr,int i, int size , int key){
    if(i==size){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return bettlin(arr, i+1, size , key);
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];
    }
    if(linsearch(arr,size,6)){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    cout<<endl;
    cout<<poslinsearch(arr,size,6)<<endl;
    cout<<bettlin(arr,0,size,12)<<endl;
    return 0;
}