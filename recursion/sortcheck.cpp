#include <iostream>
#include <stdio.h>

using namespace std;

bool sortcheck(int *arr, int size){
    if(size==1){
        return true;
    }
    if(arr[0]<arr[1] && sortcheck(arr+1, size-1)){
        return true;
    }
    return false;
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];    
    }
    if(sortcheck(arr,size)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}