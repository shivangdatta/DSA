// #include <iostream>
// #include <stdlib.h>
// // not functional

// void checkbit(int arr[], int size){

// }

// using namespace std;
// // duplicate elements linear time;
// int main(){
//     int size,xorop,tempxor,num,num2;
//     cin>>size;
//     int arr[size];
//     for(int i=0 ; i<size ; i++){
//         cin>>arr[i];
//     }
//     xorop=0;
//     for(int i=0 ; i<size ; i++){
//         xorop=xorop^arr[i];
//     }
//     tempxor=xorop;
//     int k=0;
//     while(tempxor>0){
//         if((tempxor&1)){
//             break;
//         }
//         k++;
//         tempxor=tempxor>>1;
//     }
//     num=arr[0];
//     int mask=1<<k;
//     for(int i=0 ; i<size ; i++){
//         if((mask & arr[i])!=0){
//             num=num^arr[i];
//         }
//     }
//     num2=xorop^num;
//     cout<<num<<" "<<num2<<endl;
//     return 0;
// }
// // not functional

// #include <iostream>
// #include <algorithm>

// using namespace std;
// // jump in power of 2
// int main(){
//     // cout<<"hello"<<endl;
//     int test,num,sub,count=0;
//     cin>>test;
//     for(int j=0 ; j<test ; j++){
//         cin>>num;
//         while(num!=0){
//             for(int i=0 ; i<num ; i++){
//                 if((1<<i)>num){
//                     break;
//                 }
//                 else{
//                 sub=1<<i;
//                 }
//             }
//             num=num-sub;
//             count++;
//         }
//     }
//     cout<<count<<endl;
//     return 0;
// }
// // // another approach
// #include <iostream>
// #include <algorithm>

// using namespace std;

// int main(){
//     int test;
//     cin>>test; 
//     while(test>0){
//         int num,count=1;
//         cin>>num;
//         for(int i=0 ; i<num ; i++){
//             if(num&1==1){
//                 count++;
//             }
//             num=num>>1;
//         }
//         cout<<count<<endl;
//         test--;
//     }
//     return 0;
// }
// another another approach

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int test;
    cin>>test;
    int count=0;
    while(test>0){
        int num;
        cin>>num;
        int temp=num;
        while(temp>0){
            count=count+1;
            temp=temp&(temp-1);
        }
        test--;
    }
    cout<<count<<endl;
    return 0;
}