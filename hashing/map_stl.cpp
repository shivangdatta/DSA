#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    unordered_map <string , int> map1;
    map1["mango"] = 1;
    map1["apple"] = 2;

    map1.insert(make_pair("bannana" , 24));  

    // can print indivisual buckets or can print induvisual nodes
    // printing nodes 
    for(auto node: map1){   
        cout<<node.first<<" "<<node.second<<endl;
    }
    // printing buckets
    for(int i = 0 ; i < map1.bucket_count() ; i++){
        for(auto it=map1.begin(i) ; it!=map1.end(i) ; it++ ){
            cout<<it->first<<" "<<it->second;
        }
        cout<<endl;
    }
    return 0;
}