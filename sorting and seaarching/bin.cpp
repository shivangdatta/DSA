#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdlib.h>

using namespace std;
void insertsort(int *arr ,int size){
    int num,swap;
    for(int i=0 ; i<size ; i++){
        num=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>num){
            arr[j+1]=arr[j];
        }
        arr[j+1]=num;
    }
}

int binrot(int *arr , int size , int num ){
    int beg=0 , end =size-1;
    int mid,ans =-1;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[beg]<arr[mid]){
            if(arr[beg]<=num && num<=arr[mid]){
                if(arr[mid]>num){
                    end=mid-1;
                }
                else if(arr[mid]==num){
                    ans=mid;
                    break;
                }
            }
            else if(arr[mid]<num){
                beg=mid+1;
                if(arr[mid]==num){
                    ans=mid;
                    break;
                }
            }
            else{
                cout<<"element not found ";
                break;
            }
        }
        else if(arr[mid]<arr[end]){
            if(arr[mid]<num && num<=arr[end]){
                if(arr[mid]<num){
                    beg=mid+1;
                }
                else if(arr[mid]==num){
                    ans=mid;
                    break;
                }
            }
            else if(num<arr[mid]){
                end=mid-1;
                if(arr[mid]==num){
                    ans=mid;
                    break;
                }
            }
            else{
                cout<<"element not found "<<endl;
                break;
            }
        }
    }
    return ans;
}
int main(){
    int arr[]={4,5,6,7,8,1,2,3};
    int size=sizeof(arr)/sizeof(int);
    cout<<size <<endl;
    cout<<"element found at positon : "<<binrot(arr,size, 8);
    return 0;
}