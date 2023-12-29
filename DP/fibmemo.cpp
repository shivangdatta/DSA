#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int memo[1000];

int fib(int num){
    if(num==0){
        return 0;
    }
    if(num==1){
        return 1;
    }
    if(memo[num]!=-1){
        return memo[num];
    }
    int ans = fib(num-1) + fib(num-2);
    memo[num]=ans;
    return ans;
}

int fib_dp(int num){
    int dp[1000];
    dp[0] = 0;
    dp[1] = 1;

    int curnum=2;
    for( ; curnum<=num ; curnum++){
        int ans = dp[curnum-1] + dp[curnum-2];
        dp[curnum] = ans;
    }
    return dp[num];
}
int main(){
    for(int i = 0 ; i<=1000 ; i++){
        memo[i] = -1;
    }
    int num;
    cin >> num;
    int ans = fib_dp(num);
    cout << ans;
    return 0;
}