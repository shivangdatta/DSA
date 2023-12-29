// find largest subarray of non repeating characters 
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int largestsub(string str){
    int max=1,cur=1;
    int visit_check[256];
    for(int i=0 ; i<256 ; i++ ){
        visit_check[i]=-1;
    }
    visit_check[str[0]]=0;
    for(int i=1 ; i<str.length() ; i++){
        // simple expansion 
        if(visit_check[str[i]]==-1 || i-cur==visit_check[str[i]]){
            cur=cur+1;
        }
        if(cur>max){
            max=cur;
        }
        // expansion and contraction
        else{
            if(cur>max){
                max=cur;
            }
            cur=cur-visit_check[str[i]];
        }
        if(cur>max){
            max=cur;
        }
        visit_check[str[i]]=i;
    }
    return max;
}
int main(){
    string str="abbacrte";
    int print = largestsub(str);
    cout<< print;
    return 0;
}
