#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define lld long long double

lli max_profit(lli arr[] , lli n){
    lli dp[1000][1000];
    lli year = n;
    for(lli i = 0 ; i < n ; i++){
        dp[i][i]=arr[i]*year;
    }
    for(lli len=2 ; len<=n ; len++){
        lli start = 0;
        lli end = n - len;
        while(start<=end){
            lli endwindow = start + len - 1;
            dp[start][endwindow] = max(arr[start]*year + dp[start+1][endwindow] , arr[endwindow]*year + dp[start][endwindow-1])
        }
    }

}


int main(){
    lli n ;
    lli arr[n];
    for(lli i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    return 0;
}