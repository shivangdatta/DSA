#include <iostream>
#include <cmath>

using namespace std;

void hanoistep(int disc, char source, char help, char dest){
    // base case
        if(disc==0){
            return ;
        }

    // rec case
    hanoistep(disc-1, source ,dest ,help);
    cout<<"move disc no. "<<disc<<" from "<<source<<" to "<<dest<<endl;

    hanoistep(disc-1,help , source , dest);
}

int main(){
    int num;
    cin>>num;
    hanoistep(num,'a','b','c');
    return 0;
}