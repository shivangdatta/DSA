// maximum element given size of subarray
#include <iostream>
#include <stack>
#include <deque>

using namespace std;

// using deque


int main(){
    int num;
    cin>>num;
    int arr[num];
    for(int i=0 ; i< num ; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    deque <int> q(k);
    int i;
    for(i=0 ; i<k ; i++){
        while(!q.empty() && arr[i]>=arr[q.front()]){
            q.pop_back();
        }
       
        q.push_back(i);
    }
    for(;i<num ; i++){
        cout<<arr[q.front()]<<" ";
        // remove previous 
        while(!q.empty() && q.front()<i-k){
            q.pop_front();
        }
        // remove waste
        while(!q.empty() && arr[i]>=q.front()){
            q.pop_back();
        }
        // add 
        q.push_back(i);
    }
    cout<<arr[q.front()]<<" ";
    cout<<"hello";
    return 0;
}
