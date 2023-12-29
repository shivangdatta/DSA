#include <iostream>

using namespace std;

int main(){
    int num;
    cin>>num;
    int temp=num,temprank=0,rank=0,rem,count=0,temprank2=0;
    while(temp>0){
        rem=temp%10;
        if(rem>4){
            temprank2=temprank2+(1<<count);
        }
        count++;
        temp=temp/10;
    }
    temprank=((2*(1<<(count-1)))-1);
    rank=temprank+temprank2;
    cout<<rank<<endl;
    return 0;
}
