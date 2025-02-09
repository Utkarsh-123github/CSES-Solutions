// A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
// Given n, construct a beautiful permutation if such a permutation exists.
// Input
// The only input line contains an integer n.
// Output
// Print a beautiful permutation of integers. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".

// Example 1
// Input:

// 5
// Output:

// 4 2 5 3 1
// Example 2
// Input:

// 3
// Output:

// NO SOLUTION

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>ans;
    if(n==1){
        cout<<1;
    }
    else if(n<=3 && n!=1){
        cout<<"NO SOLUTION";
    }
    else{
        for(int i=1;i<=n;i++){
            if(i%2 == 0){
                ans.push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(i%2 != 0){
                ans.push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}