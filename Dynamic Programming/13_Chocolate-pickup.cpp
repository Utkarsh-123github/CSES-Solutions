// You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

// You have two robots that can collect chocolates for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of chocolates collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the chocolates.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.
// Example:

// Input:
// n = 4, m = 3
// grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output:
// 24
// Explanation:
// Path of robot #1 and #2 are described in color green and blue respectively. Chocolates taken by Robot #1, (3 + 2 + 5 + 2) = 12. Chocolates taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of Chocolates: 12 + 12 = 24.


// This is a 3d dp prblm

#include<bits/stdc++.h>
using namespace std;
int fn(vector<vector<int>>& grid,vector<vector<vector<int>>>&dp,int n,int m, int row,int col1,int col2){
    if(col1<0 || col1>=m || col2<0 || col2>=m)return -1e8;
    if(dp[row][col1][col2] != -1)return dp[row][col1][col2];
    // base case
    if(row == n-1){
        if(col1 == col2){
            return grid[row][col1];
        }
        else return grid[row][col1] + grid[row][col2];
    }
    
    for(int dj1 = -1;dj1<=1;dj1++){
        for(int dj2 = -1;dj2<=1;dj2++){
            if(col1 == col2){
                dp[row][col1][col2] = max(dp[row][col1][col2],grid[row][col1] + fn(grid,dp,n,m,row+1,col1+dj1,col2+dj2));
            }
            else dp[row][col1][col2] = max(dp[row][col1][col2],grid[row][col1] + grid[row][col2] + fn(grid,dp,n,m,row+1,col1+dj1,col2+dj2));
        }
    }
    return dp[row][col1][col2];
}

int solve(int n, int m, vector<vector<int>>& grid) {
    // code here
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    return fn(grid,dp,n,m,0,0,m-1);
}

// TC = O(n*m*m)
// SC = O(n*m*m)