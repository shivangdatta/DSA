// q:- arrange 4X1 tilles in 4XN wall

#include <iostream>

using namespace std;

int tile(int n){
    if(n<4){
        return 1;
    }
    if(n==4){
        return 2;
    }
    return tile(n-1)+tile(n-4);
}

int main(){
    int num;
    cin>>num;
    cout<<tile(num)<<endl;
    return 0;
}