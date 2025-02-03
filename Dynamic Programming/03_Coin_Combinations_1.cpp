#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int>dp(x+1,0);
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                dp[i] = (dp[i] + dp[i-coins[j]])%mod;
            }
        }
    }
    cout<<dp[x];
    return 0;
}