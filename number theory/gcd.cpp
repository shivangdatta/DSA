#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int num1, int num2){
    if(num2==0){
        return num1;
    }
    else{
        gcd(num2,num1%num2);
    }
}

// lcm
int lcm(int a, int b){
    int ret,div;
    div=gcd(a,b);
    ret=(a*b)/div;
    return ret;
}
int main(){
    
    cout<<gcd(10,100)<<endl;
    cout<<lcm(10,15)<<endl;
    return 0;
}