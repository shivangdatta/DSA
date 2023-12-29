#include <iostream>
#include <stdio.h>

using namespace std;

void itos(int num){
    int rem=num%10;
    if(num==0){
        return;
    }
    itos(num/10);
    if(rem==1){
        cout<<"one ";
    }
    else if(rem==2){
        cout<<"two ";
    }
    else if(rem==3){
        cout<<"three ";
    }
    else if(rem==4){
        cout<<"four ";
    }
    else if(rem==5){
        cout<<"five ";
    }
    else if(rem==6){
        cout<<"six ";
    }
    else if(rem==7){
        cout<<"seven ";
    }
    else if(rem==8){
        cout<<"eight ";
    }
    else if(rem==9){
        cout<<"nine ";
    }
    else{
        cout<<"zero ";
    }
}
int main(){
    int num=6412345;
    itos(num);
    return 0;
}