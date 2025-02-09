// You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
// On each move, you may increase the value of any element by one. What is the minimum number of moves required?
// Example
// Input:

// 5
// 3 2 5 1 7
// Output:

// 5

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long ans = 0;
    for(int i=1;i<n;i++){
        int diff = arr[i]-arr[i-1];
        if(diff<0){
            ans += (-diff);
            arr[i] = arr[i-1];
        }
    }
    cout<<ans;
    return 0;
}