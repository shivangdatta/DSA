#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int test;
    cin>>test;
    for(int i=0 ; i<test ; i++){
        int n,check,count=0;
        cin>>n ;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int range=(1<<n)-1,temp,k=0,sum=0;
        for(int j=0 ; j<=range ; j++){
            temp=j;
            k=0;
            sum=0;
            while(temp>0){
                if(temp&1==1){
                    sum=sum+arr[k];
                }
                k++;
                temp=temp>>1;
            }
            if(sum==check){
                cout<<"YES"<<endl;
                count=1;
                break;
            }
        }
        if(count==0){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}