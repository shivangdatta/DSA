#include <iostream>
#include <stdlib.h>
#include <Stack>
#include <vector>

using namespace std;

class Stack{
private:
    vector <int> vec;
public:
    bool isempty(){
        if(vec.size()==0){
            return true;
        }
        return false;
    }
    void push(int key){
        vec.push_back(key);
    }
    int pop(){
        if(!isempty()){
            int ret= vec.at(vec.size()-1);
            vec.pop_back();
            return ret;
        }
        cout<<"underflow "<<endl;
        return -1;
    }
    int vecsize(){
        return vec.size();
    }
    void top(){
        cout<<vec[vec.size()-1]<<endl;
    }
    void printall(){
        for(int i=0 ; i<vec.size() ; i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
};

// reverse using two stacks 
void transfer(Stack &s1,Stack &s2){
    while(!s1.isempty()){
        int key = s1.pop();
        s2.push(key);
    }
}

// reverse using one stack
void reverse(Stack &s1 , Stack &s2){
    for(int i=0 ; i<s1.vecsize() ; i++){
        int size1=s1.vecsize();
        int temp = s1.pop();
        for(int j=i+1 ; j<size1 ; j++){
            int key=s1.pop();
            // cout<<key<<" ";
            s2.push(key);
        }
        s1.push(temp);
        while(!s2.isempty()){
            int val=s2.pop();
            s1.push(val);
        }
    }
}

void insertatbottom(Stack s1 , int x){
    if(s1.isempty()){
        s1.push(x);
        return ;
    }
    int y=s1.pop();
    insertatbottom(s1,x);
    s1.push(y);
}

void reverserec(Stack &s1){
    if(s1.isempty()){
        return ;
    }
    int x=s1.pop();
    reverserec(s1);
    insertatbottom(s1,x);
}

int main(){
    Stack s1,s2,s3;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    // s1.printall(); 
    transfer(s1,s2);
    transfer(s2,s3);
    transfer(s3,s1);  
    s1.printall(); 
    Stack s4;
    reverse(s1,s4);
    s1.printall();
    return 0;
}