#include <iostream>
#include <vector>
// optimised prime seive
using namespace std;


int main(){
    int num;
    cin>>num;
    int arr[num];
    for(int i=0 ; i<num ; i++){
      if(i%2==0){
        arr[i]=0;
      }
      else{
        arr[i]=1;
      }
    }    
    for(int i=3 ; i<=num ; i=i+2){
        if(arr[i]==1){
            for(int j=i*i ; j<=num ; j=j+(2*i)){
                cout<<"j checker : "<<j;
                    arr[j]=0;
            }
        }
    }
    for(int i=0 ; i<num ; i++){

        if(arr[i]==1){
            cout<<"prime no. :"<<i<<endl;
        }
        else{
            cout<<"dont reach condition"<<endl;
        }
    }   
    return 0;   
}