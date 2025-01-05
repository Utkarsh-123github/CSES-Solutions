// You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.
// Input
// The first input line contains an integer n.
// The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
// Output
// Print the missing number.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long long>arr(n-1);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int xorAll = 0, xorNums = 0;
    
    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorAll ^= i;
    }
    
    // XOR all elements in the given array
    for (int num : arr) {
        xorNums ^= num;
    }
    
    int ans = xorAll ^ xorNums;
    cout<<ans;
    return 0;
}