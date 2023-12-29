// #include <iostream>
// #include <stdlib.h>
// #include <algorithm>

// using namespace std;

// int main (){
//     // generating subarrays
//     int n;
//     cout<<"enter size : "<<endl;
//     cin>>n;
//     int *arr=new int[n];
//     for(int i=0 ; i<n ; i++){
//         cin>>arr[i];
//     }
//     for(int i=0 ; i<n ;i++){
//         for(int j=i ; j<n ; j++){
//             for(int k=i ; k<=j ; k++){
//                 cout<<arr[k]<<" ";
//             }
//             cout<<endl;
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main(){
    int num=0;
    string str="hello";
    cout<<(str[2]&num);
    return 0;
}