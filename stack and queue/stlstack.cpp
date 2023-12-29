#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack <string> s1;
    s1.push("hello");
    s1.push("bye");
    cout<<s1.top();
    while(!s1.empty()){
        s1.pop();
        s1.top();
    }
    // try{
    //     s1.pop();
    // }
    // catch(exception e){
    //     cout<<"empty already";
    // }
    return 0;
}