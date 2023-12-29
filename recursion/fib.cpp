#include <iostream>

using namespace std;

int fib(int num){
    int ret=0;
    if(num==0 || num==1 ){
        return num;
    }
    ret=fib(num-1)+fib(num-2);
}
int main(){
    int num;
    cin>>num;
    cout<<fib(num)<<endl;
    return 0;
}