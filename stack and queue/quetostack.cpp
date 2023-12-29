#include <iostream>
#include <queue>
#include <Stack>

using namespace std;

void stackpush(queue <int>&q1, int x){
    q1.push(x);
}

void stackpop(queue <int> &q1){
    if(q1.empty()) return;  
    queue <int> q2;
    q1.pop();
    while(!q1.empty()){
        int key = q1.front();
        q1.pop();
        q2.push(key);
    }
    while(!q2.empty()){
        int val = q2.front();
        q2.pop();
        q1.push(val);
    }
}


int main (){
    queue <int> q1; 
    queue <int> q2;
    stackpush(q1,1);
    stackpush(q1,2);
    stackpush(q1,3);
    stackpush(q1,4);
    cout<<q1.back()<<endl;
    stackpop(q1);
    cout<<q1.front()<<endl;
    return 0;
}