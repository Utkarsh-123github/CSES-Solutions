#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int>prices(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));  // here base case is also covered i.e dp[0][k] = 0 for all k (0 to n)
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            int numberOfPages = pages[i-1];
            int price = prices[i-1];
            int pick = j>=price ? dp[i-1][j-price] + numberOfPages : 0;
            int notPick = dp[i-1][j];
            dp[i][j] = max(pick,notPick);
        }
    }
    cout<<dp[n][x];
    return 0;
}