#include <iostream>
#include <stdio.h>

using namespace std;
void subgen(char *in, char*out ,int i , int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
    }
    out[j]=in[i];
    subgen(in, out,i+1, j+1);

    subgen(in,out,i+1,j);
}

// void keypadgen(int num, int rem){
//     if((rem==0 || rem==1 ) && num==0){
//         cout<<"";
//         return;
//     }
//     if(rem==2){
//         subgen("abc","",0,0);
//     }
//     else if(rem==3){
//         subgen("def","",0,0);
//     }
//     else if(rem==4){
//         subgen("ghi","",0,0);
//     }
//     else if(rem==5){
//         subgen("jkl","",0,0);
//     }
//     else if(rem==6){
//         subgen("mno","",0,0);
//     }
//     else if(rem==7){
//         subgen("pqr","",0,0);
//     }
//     else if(rem==8){
//         subgen("stuv","",0,0);
//     }
//     else{
//         subgen("wxyz","",0,0);
//     }
//     num=num/10;
//     rem=num%10;
//     keypadgen(num,rem);
// }

void keypad(char *in, char* out,int i, int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return ;
    } 

    if(in[i]=='2'){
        out[j]='a';
        keypad(in,out,i+1,j+1);
        out[j]='b';
        keypad(in,out,i+1,j+1);
        out[j]='c';
        keypad(in,out,i+1,j+1);
    }
    else if(in[i]=='3'){
        out[j]='d';
        keypad(in,out,i+1,j+1);
        out[j]='e';
        keypad(in,out,i+1,j+1);
        out[j]='f';
        keypad(in,out,i+1,j+1);
    } 
    else if(in[i]=='4'){
        out[j]='g';
        keypad(in,out,i+1,j+1);
        out[j]='h';
        keypad(in,out,i+1,j+1);
        out[j]='i';
        keypad(in,out,i+1,j+1);
    } 
    else if(in[i]=='5'){
        out[j]='j';
        keypad(in,out,i+1,j+1);
        out[j]='k';
        keypad(in,out,i+1,j+1);
        out[j]='l';
        keypad(in,out,i+1,j+1);
    } 
    else if(in[i]=='6'){
        out[j]='m';
        keypad(in,out,i+1,j+1);
        out[j]='n';
        keypad(in,out,i+1,j+1);
        out[j]='o';
        keypad(in,out,i+1,j+1);
    } 
    else if(in[i]=='7'){
        out[j]='p';
        keypad(in,out,i+1,j+1);
        out[j]='q';
        keypad(in,out,i+1,j+1);
        out[j]='r';
        keypad(in,out,i+1,j+1);
    } 
    else if(in[i]=='8'){
        out[j]='s';
        keypad(in,out,i+1,j+1);
        out[j]='t';
        keypad(in,out,i+1,j+1);
        out[j]='u';
        keypad(in,out,i+1,j+1);
    } 
    else{
        out[j]='v';
        keypad(in,out,i+1,j+1);
        out[j]='w';
        keypad(in,out,i+1,j+1);
        out[j]='x';
        keypad(in,out,i+1,j+1);
        out[j]='y';
        keypad(in,out,i+1,j+1);
        out[j]='z';
        keypad(in,out,i+1,j+1);
    }
}
int main(){
    // keypadgen();
    char  str[4];
    keypad("9123",str,0,0);
    return 0;
}