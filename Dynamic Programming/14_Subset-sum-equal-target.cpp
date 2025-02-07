// Given an array of positive integers arr[] and a value target, determine if there is a subset of the given array with sum equal to given target. 

// Examples:

// Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&arr, vector<vector<int>>&dp, int i, int target){
    if(target == 0)return true;
    if(i == arr.size()-1)return arr[i] == target;
    if(dp[i][target] != -1)return dp[i][target];
    bool taken = false;
    if(arr[i]<=target){
        taken = solve(arr,dp,i+1,target-arr[i]);
    }
    bool notTaken = solve(arr,dp,i+1,target);
    dp[i][target] = taken || notTaken;
    return dp[i][target];
}

bool isSubsetSum(vector<int>& arr, int target) {
    // code here
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return solve(arr,dp,0,target);
}