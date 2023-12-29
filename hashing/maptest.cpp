#include <iostream>
#include "hashtable.h"
#include <bits/stdc++.h>

using namespace std;


int main(){
    HashTable <int> map1;
    map1.insert("apple",100);
    map1.insert("seb",110);
    map1.insert("chilli",120);
    map1.insert("aloo",130);
    map1.insert("fruit5",140);

    if(map1.search("fruit5") == NULL){
        cout<<"not found ";
    }
    else{
        node<int> * temp = map1.search("fruit5");
        cout<<temp->value<<endl;
    }
    return 0;
}