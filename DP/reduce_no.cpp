// reduce number - div by 3 , div by 2 , -1
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int memo[1000];     

int moves_memo(int num){
    if(num==1){
        return 0;
    }
    int q1 = INT16_MAX;
    int q2 = INT16_MAX;
    int q3 = INT16_MAX;
    if(memo[num]!=-1){
        return memo[num];
    }
    if(num%3==0){
        q1 = 1 + moves_memo(num/3);
    }
    if(num%2==0){
        q2 = 1 + moves_memo(num/2);
    }
    q3 = 1 + moves_memo(num-1);
    memo[num]= min(q1 , min(q2,q3));
    return memo[num];
}
int dp[1000];
int moves_dp(int num){
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int curnum=4 ; curnum<=num ; curnum++){
        int q1 = INT_MAX;
        int q2 = INT_MAX;
        int q3 = INT_MAX;
        if(curnum%3 == 0){
            q1 = 1 + dp[curnum/3];
        }
        if(curnum%2 == 0){
            q2 = 1 + dp[curnum/2];
        }
        q3 = 1 + dp[curnum-1];
        dp[curnum]=min(q1, min(q2 , q3));
    }
    return dp[num];
}

int main(){
    for(int i = 0 ; i < 1000 ; i++){
        memo[i]=-1;
    }
    int num;
    cin >> num;
    int ans = moves_memo(num) ;
    cout << ans << endl;
    cout << "using dp (bottom-up) : " << moves_dp(num) << endl;
    return 0;
}