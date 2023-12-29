// #include <iostream>
// #include <stdio.h>
// #include <cstring>

// using namespace std;

// void subgen(char arr[] , int num){
//     int i=0;
//     while(num>0){
//         if((num&1)==1){
//             cout<<arr[i];
//         }
//         else{
//             cout<<"";
//         }
//         i++;
//         num=num>>1;
//     }
// }

// void rangegen(char *str){
//     int len=strlen(str);
//     int range=((1<<len)-1);
//     for(int i=0 ; i<=range ; i++){
//         subgen(str,i);
//         cout<<endl;
//     }
// }
// int main(){
//     char arr[100];
//     gets(arr);
//     rangegen(arr);
//     return 0;
// }


#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void mask(char * arr ,int num){
    int i=0;
    while(num>0){

    if((num&1)==1){
        cout<<arr[i];
    }
    else{
        cout<<"";
    }
    i++;
    num=num>>1;
    }
}
void range(char * s1){
    int ul=1<<strlen(s1);
    for(int i=0 ; i<=(ul-1); i++){
        mask(s1,i); 
        cout<<endl;      
    }
}
int main(){
    char str[100];
    gets(str);
    cout<<str;
    range(str);
    return 0;
}