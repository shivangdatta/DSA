#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void display(int *ptr ,int size){
    for(int i=0 ; i<size ; i++){
        cout<<ptr[i]<<" ";
    }
}
int main(){
    int *arr;
    int size,temp;
    cin>>size;
    int tempsize=size;
    arr=(int*)malloc(sizeof(int)*size);
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];
    }
    // bubble sort
    
    for(int i=0 ; i<size ; size--){
        for(int j=1 ; j<size ; j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            i++;
        }
        i=i-size+1;
    }


    // display
    for(int i=0 ; i<tempsize ; i++){
        cout<<arr[i]<<" ";
    }
    display(arr,size);
    return 0;
}