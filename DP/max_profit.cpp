#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 6, 1, 5, 5, 2, 4
int max_profit(int * arr , int start , int end , int year){

    if(start>end){
        return 0;
    }
    int right = arr[start] * year + max_profit(arr , start + 1 , end , year+1);
    int left = arr[end] * year + max_profit(arr, start , end - 1, year + 1);
    int ans = max(left , right);
    return ans;
}
int memo[1000][1000];
int max_profit_memo(int *arr , int start , int end , int year){
    if(start>end){
        return 0;
    }
    if(memo[start][end]!=-1){
        return memo[start][end];
    }
    int left =arr[start] * year + max_profit_memo(arr , start + 1 , end , year + 1);
    int right =arr[end] * year + max_profit_memo(arr, start , end-1 , year + 1);
    int ans = max(left , right);
    memo[start][end] = ans;
    return memo[start][end];
}


// bottom up approach

int max_prof(int *arr , int n){
    int dp[100][100] = {};
    int year = n;
    for(int i = 0 ; i < n ; i++){
        dp[i][i] = arr[i] * year ;
    }
    year --;

    for(int len=2 ; len <= n ; len++){
        int start = 0 ;
        int end = n -len  ;
        while(start <=end){
            int endwindow = start + len -1 ;
            dp[start][endwindow] = max((arr[start] * year + dp[start+1][endwindow]) , (arr[endwindow] * year + dp[start][endwindow-1]));
            start++;
        }
        year--;
    }
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cout<< setw(3) << dp[i][j] ;
        }
        cout << endl;
    }
    return dp[0][n-1];
}

int main(){
    int size;
    cin >> size ;
    int arr[size];
    memset(memo , -1 , sizeof(memo));
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i] ;
    }
    int ans = max_prof(arr , size);
    cout << ans << endl;
    return 0;
}