#include <iostream>
#include <vector>
#include <Stack>

using namespace std;

bool balcheck(string str){
    stack <char> s1;
    for(int i=0 ; i<str.length() ; i++){
        if(str[i]=='('){
            s1.push(str[i]);
        }
        if(str[i]==')'){
            if(s1.empty() || s1.top()!='('){
                return false;
            }
            else{
                s1.pop();
            }
        }
    }
    if(s1.empty()){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    string str1="((()))a()";
    if(balcheck(str1)){
        cout<<"yes "<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}