#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;
// finding square root using binarysearch

// int binsqrt(int num){
//     int beg=0, end=num;
//     int mid,ans=-1;
//     while(beg<=end){
//         mid=(beg+end)/2;    
//         if(mid*mid<num){
//             ans=mid;
//             beg=mid+1;
//         }
//         if(mid*mid>num){
//             end=mid-1;
//         }
//         else if(mid*mid==num){
//             ans=mid;
//             return ans;
//         }
//     }  
//     return ans;  
// }

float binsqrt(int num, int prec){
    int beg=0, end=num;
    int check=0;
    int mid,ans=-1;
    float decimal;
    while(beg<=end){
        mid=(beg+end)/2;
        if(mid*mid<num){
            ans=mid;
            beg=mid+1;
        }
        else if(mid*mid>num){
            end=mid-1;
        }
        else if(mid*mid==num){
            ans=mid;
            return ans;
        }
    }
    decimal=float(ans);
    float inc=.1;
    // for(int i=1 ; i<10 ; i++ ){
    //     inc=inc*i;
    //     if((decimal+inc)*(decimal+inc)<num){
    //         decimal=decimal+inc;
    //     }
    //     else if((decimal+inc)*(decimal+inc)>num){
    //         i=1;
    //         inc=inc/10;
    //         check++;
    //         if(check==prec){
    //             break;
    //         }
    //         continue;
    //     }
    // }
    for(int i=0 ; i<prec ;i++){
        for(int j=1 ; j<10 ;j++){
            inc=inc*float(j);
            if((decimal+inc)*(decimal+inc)<j){
                decimal=decimal+inc;
            }
            else if((decimal+inc)*(decimal+inc)>=j){
                inc=inc/float(j);
                break;
            }    
        }
        inc=inc/10;
    }
    return decimal;
}
int main(){
    // int num;
    // cin>>num;
    // cout<<binsqrt(num);
    int num2,prec;
    cin>>num2>>prec;
    cout<<binsqrt(num2,prec);
    return 0;
}