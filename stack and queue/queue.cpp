#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T>
class Que{
private : 
    T *arr;
    int front;
    int rear;
    int maxsize;
    int cursize;
public: 
    Que(){
        cout<<"im default";
    }
    Que(int size){
        front=0;
        rear=0;
        maxsize=size;
        arr=new T[size];
        cursize=0;
    }
    bool isempty(){
        if(cursize==0){
            return true;
        }
        return false;
    }

    bool isfull(){
        if(cursize==maxsize){
            return true;
        }
        return false;
    }

    void enque(T key){
        cout<<rear<<endl;
        if(!isfull()){
            arr[rear]=key;
            cout<<arr[rear]<<endl;
            rear=(rear+1)%maxsize;
            cursize++;
        }
        else{
            cout<<"overflow"<<endl;
        }
    }
    void deque(){
        if(!isempty()){
            front=(front+1)%maxsize;
            cursize--;
        }
        else{
            cout<<"underflow"<<endl;
        }
    }
    void printfront(){
        cout<<arr[front]<<endl;
    }
};

int main(){
    int size;
    cin>>size;
    Que <int> *q1= new Que<int>(size);
    q1->enque(4);
    q1->enque(5);
    q1->enque(6);
    q1->enque(7);
    q1->deque();
    q1->deque();
    q1->deque();
    q1->deque();
    q1->deque();
    q1->deque();
    return 0;
}