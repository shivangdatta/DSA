// find power of number effeciently
#include <iostream>
#include <stdio.h>

using namespace std;
int pownum(int num, int pow){
    if(pow==1){
        return num;
    }
    return num*pownum(num,pow-1);
}

int effpownum(int num, int pow){
    if(pow==1){
        return num;
    }
    if(pow%2==0){
        return effpownum(num,pow/2)*effpownum(num,pow/2);
    }
    else{
        return num*effpownum(num,pow/2)*effpownum(num,pow/2);
    }
}
int main(){
    int num=2,pow=3;
    cout<<effpownum(num,pow)<<endl;
    return 0;
}