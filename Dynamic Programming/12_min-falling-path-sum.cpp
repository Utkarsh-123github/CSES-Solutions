#include<bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    // base case
    for(int i=0;i<n;i++){
        dp[n-1][i] = arr[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int path1 = arr[i][j] + dp[i+1][j];
            int path2 = 0;
            if(j-1>=0){
                path2 = arr[i][j] + dp[i+1][j-1];
            }
            else{
                path2 = INT_MAX;
            }
            int path3 = 0;
            if(j+1 < n){
                path3 = arr[i][j] + dp[i+1][j+1];
            }
            else path3 = INT_MAX;
            dp[i][j] = min(path1,min(path2,path3));
        }
    }
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        mini = min(dp[0][i],mini);
    }
    return mini;
}