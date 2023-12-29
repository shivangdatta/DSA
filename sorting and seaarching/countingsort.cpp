#include <iostream>
#include <algorithm>

// incorrect
using namespace std;
void countsort(int *arr, int size){
    int fre[size];
    for(int i=0 ; i<size ; i++){       
        fre[arr[i]]++;
    }
    for(int i=0 ; i<size ; i++){
        if(fre[i]>0){
            for(int j=0 ; j<fre[i]; j++){
                cout<<arr[j];
            }
        }
    }
}
void display(int *arr, int size ){
    // for(int i=0 ; i<size ; i++)

        
}

int main(){

    return 0;
}