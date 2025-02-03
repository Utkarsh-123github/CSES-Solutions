#include<bits/stdc++.h>
using namespace std;

// Method 1
// int extractHighestDigit(int n){
//     int maxi = 0;
//     while(n!=0){
//         int x = n%10;
//         maxi = max(maxi,x);
//         n = n/10;
//     }
//     return maxi;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin>>n;
//     int cnt = 0;
//     while(n != 0){
//         int maxi = extractHighestDigit(n);
//         n = n-maxi;
//         cnt++;
//     }
//     cout<<cnt;
//     return 0;
// }

// Method 2
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>dp(n+1,1e8);
    dp[0] = 0;

    for(int i=1;i<=n;i++){
        string a = to_string(i);
        for(char c:a){
            int digit = c-'0';
            if(digit!=0){
                dp[i] = min(dp[i],dp[i-digit] +1 );
            }
        }
    }
    cout<<dp[n];
    return 0;
}