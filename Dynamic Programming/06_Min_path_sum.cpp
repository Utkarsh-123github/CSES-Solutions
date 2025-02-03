// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

#include<bits/stdc++.h>
using namespace std;

// Intuition
// DP state : dp[i][j] = min path sum from (0,0) to (i,j)
// Hence dp[n-1][m-1] = min path sum from (0,0) to (n-1,m-1);
// Base case: dp[0][0] = grid[0][0] i.e cost to travel from (0,0) to (0,0) = value of grid[0][0]
// Edge case: if(i<0 || j<0) i.e out of grid, then return 1e9
// Transition: up = grid[i][j] + dp[i-1][j];
//             left = grid[i][j] + dp[i][j-1]
//             dp[i][j] = min(left,up);
// return dp[n-1][m-1]

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
            }
            else{
                int up = grid[i][j];
                int left = grid[i][j];
                if(i>0){
                    up += dp[i-1][j];
                }
                else up += 1e8;
                if(j>0){
                    left += dp[i][j-1];
                }
                else left += 1e8;
                dp[i][j] = min(left,up);
            }
        }
    }
    return dp[n-1][m-1];
}

