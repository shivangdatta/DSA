// #include <iostream>
// #include <vector>
// #include <bits/stdc++.h>


// using namespace std;

// // pair of elements which sum to 0
// // double counting problem 

// int main(){
//     unordered_map <int , bool> map;
//     int size;
//     cin >> size;
//     int arr[size];
//     for(int i = 0 ; i < size ; i++){
//         cin >> arr[i];
//         map.insert(make_pair(arr[i], true));
//     }
//     vector <pair<int , int >> vec;   
//     for(auto ind:map ){
//         if(auto search = map.find(-ind.first) ; search!=map.end()){
//             vec.push_back(make_pair(ind.first , search->first));
//         }
//         else{
//             continue;
//         }
//     }

//     for(int i = 0 ; i <vec.size() ; i++){
//         cout<<vec[i].first<<" "<<vec[i].second<<endl;
//     }
//     return 0;
// }


#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// union and intersection of two linked list

class node {
    public:
        int data;
        node * next ;
        node (int key ){
            data = key;
            next = NULL;
        } 
};


int main(){
    
    return 0;
}