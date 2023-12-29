#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
// int *binrot(int arr[] , int size, int num){
//     int beg=0,end=size-1;
//     int mid, ans=-1;
//     while(beg<=end){
//         mid=(beg+end)/2;
//         if(arr[beg]<=arr[mid]){
//             if(num<arr[mid] && arr[]){
//                 end=mid-1;
//             }
//             else if(num>arr[mid]){
//                 beg=mid+1;
//             }
//         }
//         else if(arr[mid]<arr[end]){

//         }
//     }
    
// }

int binrot(int *arr , int size , int num){
    int beg=0 , end=size-1;
    int mid,ans=-1;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[beg]<arr[mid]){
            if(arr[beg]<=num<=arr[mid]){
                end=mid-1;
                mid=(beg+end)/2;
                if(arr[mid]>num){
                    end=mid-1;
                }
                else if(arr[mid]==num){
                    ans=mid;
                    break;
                }
            }
            else if(num>arr[mid]){

                if(arr){

                }
            }
        }
        else if(arr[mid]<arr[end]){

        }
    }
    return ans;
}
int main(){
    int arr[]={4,5,1,2,3};
    int size =5;

    return 0;
}