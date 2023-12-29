// find k largest numbers in a running stream
// make heap of size k - ans
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    priority_queue <int ,vector <int> , greater <int>> pq_min;

    int feed;
    int size=0;
    int k;
    while(scanf("%d",&k)!=EOF){
        if(size==k){
            if(k>pq_min.top()){
                pq_min.pop();
                size--;
            }
            else{
                continue;
            }
        }
        pq_min.push(k);
        size++;
        if(k==-1){
            //  some printing using function
        }
    }
    return 0;
}