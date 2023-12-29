#include <iostream>
// #include <algorithm>
#include <vector>

using namespace std;

void input(int *arr,int size){
    for(int i=0 ;i<size ;i++ ){
        cin>>arr[i];
    }
}
void display(int *arr ,int size){
    for(int i=0 ; i<size ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void sort(int *arr, int size){
    int min,temp;
    for(int i=0 ; i<size ; i++){
        min=arr[i];
        for(int j=i ;j<size ;j++){
            if(arr[j]<min){
                min=j;
                temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
        }
    }
}
int main(){
    int *arr,size;
    cout<<"enter size :"<<endl;
    cin>>size;
    arr=(int*)malloc(sizeof(int)*size);
    input(arr,size);
    display(arr,size);
    sort(arr,size);
    display(arr,size);
    return 0;
}