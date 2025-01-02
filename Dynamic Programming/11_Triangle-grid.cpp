#include<bits/stdc++.h>
using namespace std;


int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>>dp(n,vector<int>(n,-1)); // State : dp[i][j] min path sum from arr[i][j] to last row of the triangle
    // base case
    for(int i=0;i<n;i++){
        dp[n-1][i] = triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j]; // transition
        }
    }
    return dp[0][0]; // i.e return min path sum from arr[0][0] to the last row
}