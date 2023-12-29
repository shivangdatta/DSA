#include <iostream>
#include <stdlib.h>

using namespace std;

void printarr(int * arr , int size){
    for(int i =0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
// printarr works fine

int *staticcreatearray(int size){
    int arr[size] = {1,2,3,4,5};
    printarr(arr,size);
    return arr;
}
// this staticcreation cannot be returned
// to solve this we use dynamic memory allocation

int *dynamiccreate(int size){
    int *arr = new int [size];
    for(int i =0 ; i<size ;i++){
        arr[i]=i+1;
    }
    printarr(arr,size);
    return arr;
}

int ** create2d(int row , int col){
    int ** arr = new int*[row];
    for(int i=0 ; i<row ; i++){
        arr[i]= new int [col];
    }
    return arr;
}
int main(){
    // int * check= staticcreatearray(5);
    // int check[5] = {1,2,3,4,5};
    int size;
    int col;
    cout<<"enter size ";
    cin>>size>>col;
    int **check = create2d(size,col);

    // printarr(check,5);
    return 0;
}