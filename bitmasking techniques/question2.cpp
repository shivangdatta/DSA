// // lucky number rank
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main(){
//     int test;
//     cin>>test;
//     while(test>0){
//         int num,rank=0,temprank=0,countg=0,tempdig;
//         cin>>num;
//         int countdig=0;
//         int temp=num;
//         while(temp>0){
//             countdig++;
//             tempdig=temp%10;
//             if(tempdig>4){
//                 countg++;
//             }
//             temp=temp/10;
//         }
//         for(int i =1 ; i< countdig; i++){
//             temprank=temprank+(1<<i);
//         }
//         rank=temprank+(1<<countg);
//         test--;
//         cout<<rank<<endl;
//     }
//     return 0;
// }

// // find the unique number

// // #include <iostream>
// // #include <cmath>

// // using namespace std;

// // int main(){
// //     int test;
// //     cin>>test;
// //     while(test>0){
// //         int size;
// //         cin>>size;
// //         int arr[size];
// //         for(int i=0 ; i<size ; i++){
// //             cin>>arr[i];
// //         }
// //         int xorop=arr[0];
// //         for(int i=1 ; i<size ; i++){
// //             xorop=xorop^arr[i];
// //         }
// //         cout<<xorop<<endl;
// //         test--;
// //     }
// //     return 0;
// // }

