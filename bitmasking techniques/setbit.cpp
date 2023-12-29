#include <iostream>
#include <cmath>

using namespace std;
int checkbits(int num){
    int count=0;
    while(num>0){
        count+=(num&1);
        num=num>>1;
    }
    return count;
}
int fastbitcheck(int num){
    int count=0; 
    while(num>0){
        num=num&(num-1);
        count++;
    }
    return count;
}

void swap(int *num1 ,int *num2){
    *num1=(*num1)^(*num2);
    *num2=*num2^*num1;
    *num1=*num1^(*num2);
}

int main(){
    // int num;
    // cin>>num;
    // cout<<checkbits(num)<<endl;
    // cout<<fastbitcheck(num);
    int test1,test2;
    cin>>test1>>test2;
    swap(test1,test2);
    cout<<"values after change are : "<<test1<<" and "<<test2;
    return 0;
}