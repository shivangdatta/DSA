#include <iostream>
#include <cstring>

using namespace std;

bool ratmaze(char in[][10] , int out[][10], int i , int j , int m, int n){
    if(i==m && j==n ){
        // print 
        for(int k=0 ; k<=m ; k++){
            for(int l=0 ; l <=m ; l++){
                cout<<out[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(i>m || j>n){
        return false;
    }
    if(in[i][j]=='B'){
        return false;
    }
    out[i][j]=1;

    // recursion

    bool goright=ratmaze(in,out,i,j+1,m,n);
    bool godown=ratmaze(in,out,i+1,j,m,n);
    
    out[i][j]=0;

    if(goright || godown){
        return true;
    }
    return false;
}
int main(){
    int sol[10][10]={0};
    char in[10][10];
    int row,col;
    cin>>row>>col;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cin>>in[i][j];
        }
    }
    if(ratmaze(in,sol,0,0,row-1,col-1))cout<<"yes";
    return 0;
}