#include <iostream>
#include <vector>

using namespace std;

class Heap{
private :
    vector <int> vec;
    bool ismin;
public : 
    Heap(bool type = true){
        ismin = type;
        vec.push_back(-1);
    }

    bool compare(int a , int b ){
        if(ismin){
            return a < b;
        }
        else{
            return a > b;
        }
    }
    void push(int key){
        vec.push_back(key);

        int index = vec.size()-1;
        int parent = index/2;

        while(index>1 && compare(vec[index] , vec[parent])){
            swap(vec[index] , vec[parent] );
            index = parent;
            parent= parent/2;
        }
    }
    bool isempty(){
        if(vec.size()==0){
            return true;
        }
    }
    int top(){
        return vec[1];
    }
    void pop(){
        swap(vec[1], vec[vec.size()-1]);

        // deleting the last element
        vec.pop_back();

        // swapping values till we reach last nodes
        int index = 1;
        int child1 = index * 2;
        int child2 = child1 + 1;
        while(child1<vec.size() && child2<vec.size() ){
            if(compare(vec[child1] ,vec[index]) || compare (vec[child2], vec[index])){
                int rep;
                if(ismin){
                    rep = min (vec[child1] , vec[child2]);
                }
                else{
                    rep = max (vec[child1] , vec[child2]);
                }
                if(rep==vec[child1]){
                    swap(vec[index] , vec[child1]);
                    index = child1;
                }
                else if(rep==vec[child2]){
                    swap(vec[index] , vec[child2]);
                    index = child2;
                }
                child1 = index * 2;
                child2 = child1 + 1;
            }
        }
    }

};

int main(){
    Heap H;
    H.push(5);
    H.push(2);
    H.push(4);
    H.push(15);
    H.push(9);
    H.push(14);
    H.push(8);
    cout<<H.top()<<endl;
    H.pop();
    cout<<H.top()<<endl;
    H.pop();
    // H.pop();
    // H.pop();

    cout<<H.top()<<endl;
    return 0;
}