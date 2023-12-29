// #include <iostream>
// #include <stdio.h>

// using namespace std;

// void decprint(int num){
//     if(num==1){
//         cout<<"1"<<endl;
//         return;
//     }
//     cout<<num<<endl;
//     decprint(num-1);
// }
// void incprint(int num){
//     if(num==1){
//         cout<<"1"<<endl;
//         return;
//     }
//     incprint(num-1);
//     cout<<num<<endl;
// }
// int main(){
//     int num;
//     cin>>num;
//     incprint(num);
//     decprint(num);
//     return 0;
// }

// multiplication using recursion
// converting string to integer using recursion
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
int mul(int num1, int num2){
    if(num2==0){
        return 0;
    }
    return num1=num1+mul(num1,num2-1);
}
int stoi(char *str, int size){
    int dig;
    if(size==0){
        return 0;
    }
    if(str[0]=='0'){
        dig=0;
    }
    else if(str[0]=='1'){
        dig=1;
    }
    else if(str[0]=='2'){
        dig=2;
    }
    else if(str[0]=='3'){
        dig=3;
    }
    else if(str[0]=='4'){
        dig=4;
    }
    else if(str[0]=='5'){
        dig=5;
    }
    else if(str[0]=='6'){
        dig=6;
    }
    else if(str[0]=='7'){
        dig=7;
    }
    else if(str[0]=='8'){
        dig=8;
    }
    else{
        dig=9;
    }
    return (dig*(pow(10,size-1)))+stoi(str+1,size-1);
}
int main(){
    // int num1=2,num2=3;
    cout<<mul(4,3)<<endl;
    char * str="82345";
    cout<<stoi(str,5)<<endl;
    return 0;
}