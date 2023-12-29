// given integer array find the span of each day
#include <iostream>
#include <vector>
#include <Stack>

using namespace std;

int stackpusher(stack <int> &s1 , int key , int pos){
    int ret;
    if(s1.empty()){
        s1.push(pos);
        return pos;
    }
    if(key<s1.top()){
        s1.push(pos);
    }
    if(key>s1.top()){
        while(key>s1.top()){
            if(s1.empty()) break ; 
            s1.pop();
        }
        s1.push(pos);
    }
    int ab , bel=0;
    ab=s1.top();
    s1.pop();
    if(!s1.empty()){
        bel=s1.top();
    }
    s1.push(ab);
    ab=ab-bel;
    return ab;
}

int * spanfinder(int *arr , int size){
    int ret[size];
    stack <int>s1;
    for(int i=0 ; i<size ; i++){
        int insert = stackpusher(s1 , arr[i] , i);
        ret[i]=insert;
    }
}


void printarr(int *arr , int size ){
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[7]={100,80,60,70,60,75,85};
    int * printme;
    printme=spanfinder(arr, 7);
    printarr(printme, 7);
    return 0;
}