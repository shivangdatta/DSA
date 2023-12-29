#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int getibit(int num , int i){
    int temp=num;
    int dig;
    temp>>i;
    dig=(temp&1);
    return dig;    
}
// set bit on the i-th position to 1;
void setibit(int *num , int i){
    int mask=1<<i;
    *num=(*num|mask);
}

void clearibit(int *num, int i){
    int mask=1<<i;
    mask= ~mask;
    *num=(*num & mask);
    // return *num;
}

// generating all subsets of a given set using bitmasking :-
void masker(char *a, int num){
    int i=0;
    while(num>0){
        if(num&1==1){
            cout<<a[i];
        }
        if(num&1==0){
            cout<<"";
        }
        // (num&1)?cout<<a[i]:cout<<"";
        i++;
        num=num>>1;
    }
    cout<<endl;
}
void subset(char *a){
    int len=strlen(a);
    int range=(1<<len) -1;
    for(int i=0 ; i<=range ; i++){
        masker(a,i);
    }
    // cout<<endl;
}
int main(){
    // int num,i;
    // cin>>num>>i;
    // cout<<getibit(num,i);
    // int num2,i2;
    // cin>>num2>>i2;
    // cout<<"original num2 : "<<num2<<endl;
    // // setibit(&num2, i2);
    // // cout<<"new num2 is : "<<num2;
    // clearibit(&num2,i2);
    // cout<<"new num2 is "<<num2<<endl;
    // string str="abc";
    char str[100];
    cin>>str;
    subset(str);
    return 0;
}