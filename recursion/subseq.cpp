#include <iostream>
#include <stdio.h>

using namespace std;

void subgen(char * in , char *out, int i, int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    // recursive cases
    out[j]=in[i];
    subgen(in,out,i+1,j+1);
    subgen(in,out,i+1,j);
}
int main(){
    char str[100],out[110];
    cin>>str;
    subgen(str,out,0,0);
    return 0;
}