#include <iostream>
#include <stdio.h>

using namespace std;

# define arr={'a','b','c','d','e','f','g','h','i'};
int mask(char *str,int num){
    int i=0;
    while(str>0){
        if(num&1==1){
            cout<<str[i]
        }
        else{
            cout<<"";
        }
        num=num>>1;
        i++;
    }
}
void keypad(char *str){
    if(str==0){
        return;
    }
    if(num==1){
        return;
    }
    
}

int main(){

    return 0;
}