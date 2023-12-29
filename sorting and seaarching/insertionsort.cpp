#include <iostream>
#include <math.h>

using namespace std;
void sort(int *arr,int size){
    int num;
    for(int i=0 ; i<size ; i++){
        num=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>num){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=num; 
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
    sort(arr,6);
    display(arr,6);
    return 0;
}