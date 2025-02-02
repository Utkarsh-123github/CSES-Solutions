// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
// For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
// Input
// The first input line has two integers n and x: the number of coins and the desired sum of money.
// The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
// Output
// Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
// Constraints

// 1 \le n \le 100
// 1 \le x \le 10^6
// 1 \le c_i \le 10^6

// Example
// Input:
// 3 11
// 1 5 7

// Output:
// 3


#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int>dp(x+1,1e9);
    dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(int j = 0;j<n;j++){
            if(coins[j]<=i){
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    if(dp[x] == 1e9){
        cout<<-1;
    }
    else cout<<dp[x];
    return 0;
}