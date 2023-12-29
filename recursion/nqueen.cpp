#include <iostream>
#include <cmath>

using namespace std;

// #define size =15

bool poscheck(int num[][10],int size, int ip, int jp){
    int tempi=ip,tempj=jp;
    // int count=1; 
    // vertical
    while(0<=tempi){
        if(num[tempi][jp]==1){
            return false;
        }
        tempi--;
    }
    // left diagonal 
    tempi=ip,tempj=jp;
    while(0<=tempi && 0<=tempj){
        if(num[tempi][tempj]==1){
            return false;
        }    
        tempi--;
        tempj--;
    }
    // right diagonal
    tempi=ip,tempj=jp;
    while(0<=tempi && tempj<size){
        if(num[tempi][tempj]==1){
            return false;
        }
        tempi--;
        tempj++;
    }
    // checked for both 
    return true;
}
bool chessqueen(int arr[][10] , int i , int size){
    if(i==size){
        for(int k=0 ; k<size ; k++){
            for(int m=0 ; m<size ;m++){
                if(arr[k][m]==1){
                    cout<<" Q ";
                }
                else{
                    cout<<" - ";
                }
            }
            cout<<endl;
        }
        return true;
    }

    for(int j=0 ; j<size ; j++){
        if(poscheck(arr,size ,i ,j )){
            arr[i][j]=1;
            bool iscor=chessqueen(arr,i+1,size);
            if(iscor){
                return true;
            }
            arr[i][j]=0;
        }
    }
    return false;
}
int main(){
    int arr[10][10];
    int size;
    cin>>size;
    chessqueen(arr, 0, size);
    return 0;
}