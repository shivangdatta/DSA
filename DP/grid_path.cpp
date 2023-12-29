#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 2d array find least cost path 


int path_weight(int row , int col ,int **arr){
    int dp[row][col];
    memset(dp , -1 , sizeof(dp));
    int cur1 = 0 , cur2 = 0;
    dp[cur1][cur2] = arr[cur1][cur2];
    for(int i = 1 ; i < col ; i++){
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }
    for(int i = 1 ; i < row ; i++){
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }
    cur1++,cur2++;
    for( ;cur1<=row-1 ; cur1++){
        for(cur2=1 ;cur2<=col-1 ; cur2++){
            int q1 = dp[cur1][cur2-1] + arr[cur1][cur2];
            int q2 = dp[cur1-1][cur2] + arr[cur1][cur2];
            dp[cur1][cur2] = min(q1,q2);
        }
    }

    // for(int i = 0 ; i < row ; i++ ){
    //     for(int j = 0 ; j < col ; j++ ){
    //             cout<<setw(3) << dp[i][j] <<" "; 
    //     }
    //     cout << endl;
    // }
    return dp[row-1][col-1];
}   

int main(){
    int row , col;
    cin >> row >> col;
    int** arr = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++)
        arr[i] = (int*)malloc(col * sizeof(int));
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>arr[i][j];
        }
    }
    int ans = path_weight(row , col , arr);
    cout << ans << endl;
    return 0;
}