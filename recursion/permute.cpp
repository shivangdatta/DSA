// #include <iostream>
// #include <cstring>
// #include <cmath>
// using namespace std;
 
// int fac(int num){
//     if(num==1 || num==0){
//         return 1;
//     }
//     return num*fac(num-1);
// }

// // void permute(char *in, char *out,int i, int j){
// //     // base case
// //     int count=0;
// //     if(in[i]=='\0'){
// //         out[i]='\0';
// //         cout<<out<<",";
// //         return;    
// //     }
// //     // recursive cases
// //     out[j]=in[i];
// //     permute(in,out,i+1,j+1);
// //     permute(in , out , i+1 , j);
// // }
// void swapper(char * num1, char * num2);
// void permute(char * in , int i , int j){
//     if(in[i]=='\0' || in[j]=='\0'){
//         cout<<in<<endl;
//         return;
//     }
//     for(int k=i ; k<=strlen(in) ; k++){
//         swapper(in+i,in+j);
//         permute(in, i+k , i+j);
//     }
// }
// void swapper(char *num1 , char *num2){
//     *num1=*num1^(*num2);
//     *num2=*num2^(*num1);
//     *num1=*num1^(*num2);
// }
// int main(){
//     char str[100];
//     char out[100];
//     cin>>str;
//     // for(int i = 0 ; i<strlen(str) ; i++){
//     //     for(int j=i+1 ; j<strlen(str) ; j++){
//     //         // cout<<endl;
//     //         swapper(str+i,str+j);    
//     //         cout<<str;
//     //         cout<<endl;
//     //     }
//     // }
//     // for(int i = 0 ; i<strlen(str) ; i++){
//     //     for(int j=i+1 ; j<strlen(str) ; j++){
//     //         // cout<<endl;
//     //         swapper(str+i,str+j);    
//     //         cout<<str;
//     //         cout<<endl;
//     //     }
//     // }
//     permute(str,0,0);
//     return 0;
// } 


// actual solution

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

void permute(char *in, int i){
    // base case
    if(in[i]=='\0'){
        cout<<in<<",";
        return;
    }
    for(int j=i ; j<strlen(in) ; j++ ){
        swap(in[i],in[j]);
        // recursion
        permute(in,i+1);
        // backtracking
        swap(in[i],in[j]);
    }
}
int main(){
    char str[190];
    cin.getline(str,4);
    permute(str,0);
    return 0;
}