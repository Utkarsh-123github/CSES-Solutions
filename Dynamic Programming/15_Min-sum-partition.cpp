
// Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.

// Examples:

// Input: arr[] = [1, 6, 11, 5]
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11 
// Hence, minimum difference is 1.  
// Input: arr[] = [1, 4]
// Output: 3
// Explanation: 
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {4}, sum of Subset2 = 4
// Hence, minimum difference is 3.

#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>& arr, int target,vector<vector<bool>>&dp) {
    // code here
    int n = arr.size();
    
    // base case
    //1. if target == 0 then for every array of different size answer is true
    
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    //2. if array size = 1(i==0) then for every target value answer is false except one value where target = arr[0]
    if(arr[0] <= target){
        dp[0][arr[0]] = true;
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notPick = dp[i-1][j];
            bool pick = false;
            if(arr[i] <= j){
                pick = dp[i-1][j-arr[i]];
            }
            dp[i][j] = pick || notPick;
        }
    }
    
    return dp[n-1][target];
}

int minDifference(vector<int>& arr) {
    // Your code goes here
    int n = arr.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    
    vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
    bool generateTabulation = isSubsetSum(arr,sum,dp);
    
    int rangeOfS1 = sum/2;
    int mini = INT_MAX;
    for(int i=0;i<=rangeOfS1;i++){
        if(dp[n-1][i] == true){
            mini = min(mini,(sum-2*i));
        }
    }
    return mini;
    
}