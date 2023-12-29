#include <iostream>
#include <vector>

using namespace std;
// can also use templates 

// template <class T , typename X>
//template used  in above line
class Stack{
private:
    vector <int> vec;
public:
    void push(int data){
        vec.push_back(data);
    }
    bool isempty(){
        if(vec.size()==0){
            return true;
        }
    }
    void pop(){
        if(!isempty()){
            vec.pop_back();
        }
        else{
            cout<<"empty warning "<<endl;
        }
    }
    int top(){
        return vec[vec.size()-1];
    }
};

int main(){
    Stack st1 ;
    st1.push(10);
    st1.push(11);
    st1.push(12);
    st1.push(13);
    cout<<st1.top()<<endl;
    
    return 0;
}