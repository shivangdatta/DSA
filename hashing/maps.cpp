#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    unordered_map<string , int> map1;
    map1["fruit1"] = 100;
    
    map1.insert(make_pair("fruit2" , 110));

    if(map1.count("fruit1")==1){
        cout<<"price of fruit1 is : "<<map1["fruit1"]<<endl;
    }

    map1["fruit3"] = 120;

    auto iter = map1.find("fruit3");
    if(iter != map1.end()){
        cout<<"price of fruit 3 is : "<<map1["fruit3"];
    }
    else{
        cout<<"element not found";
    }

    return 0;
}