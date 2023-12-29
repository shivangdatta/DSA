#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int memo[1000];

int maxprofit(int costperlen[] , int length){
    if(length==0){
        return 0;
    }
    if(memo[length]!=-1)return memo[length];
    int best = -1;
    for(int i = 1 ; i <=length ; i++){
        int profit = costperlen[i] + maxprofit(costperlen , length - i);
        best = max(best , profit);
    }
    memo[length] = best;
    return best;
}


int maxprofit_bu(int costperlen[] , int length){
    int dp[1000]={};
    // dp[0]=0;
    for(int i = 1 ; i <=length ; i++){
        int best = 0;
        for(int j = 1 ; j <=i ; j++){
            best = max(best, dp[i-j] + costperlen[j]);
        }
        dp[i] = best;
    }
    return dp[length];
}

int main(){
    memset(memo , -1 , sizeof(memo)); 
    int length;
    int costperlen[1000]; costperlen[0] = 0;
    cin >> length;
    for(int i = 1 ; i<=length ;i++){
        cin >> costperlen[i];
    }
    int ans = maxprofit_bu(costperlen , length);
    cout << ans << endl;
    return 0;
} 