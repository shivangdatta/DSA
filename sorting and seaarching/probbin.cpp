#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

bool mycomp(pair <string ,int> p1,  pair <string ,int > p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    else {
        return p1.second<p2.second;
    }
}
// bool mycomp2(pair<string, int> p1, pair <string ,int> p2){
//     if(p1.first==p2.first){
//         return p1.first>p2.first;
//     }
//     return p1.first>p2.first;
// }
int main(){
    int minsal;
    cin>>minsal;
    int size ;
    cin>>size;
    pair <string , int> sal [size];
    string name;    
    int my_sal;
    for(int i=0 ; i<size ;i++){
        cin>>name>>my_sal;
        sal[i].first=name;
        sal[i].second=my_sal;
    }
    sort(sal,sal+size,mycomp);
    
    for(int i=0 ; i<size ; i++){
        // if(sal[i].second==sal[i+1].second){
        //     sort(sal+i,sal+i+1,mycomp2);
        // }
        cout<<"name is : "<<sal[i].first<<endl;
        cout<<"sal is : "<<sal[i].second<<endl;
    }
    return 0;
}